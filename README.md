# ogl_game
opengl for a game.


---------------------------------

### Tips

1. 重构目录结构
    - 以sln文件为中心，向内gengine是engine文件，向外忽略(本来还有一层src，在该项目中省略，`因为它其实不属于sln`)。

---------------------------------

### Video

1. skip
2. skip
3. skip
4. 创建解决方案-默认会创建一个项目-配置该项目
    - 删除debug中除了x64之外的版本；
    - 设定gengine输出为dll
    - 设定全局属性：
        - 输出目录：`$(SolutionDir)bin\$(Configuration)-$(Platform)\$(ProjectName)\`
        - 中间目录：`$(SolutionDir)tmp\$(Configuration)-$(Platform)\$(ProjectName)\`
    - 添加一个新项目-应用项目（都被sln管理）：
        - 同样删除x64之外的版本
        - 同样设定全局属性
        - 设置该项目为启动项目（可以通过修改sln中的前后顺序来更改）
    - 将gengine链接到sandbox（可以通过属性-链接器-命令行确认）
    - 点击“显示全部文件”让目录结构显示更加清晰
    - 框架测试：
        ```c++
        // 在gEngine中：
        __declspec(dllexport) void print() {printf("Hello engine!");}

        // 在SandBox中：
        __declspec(dllimport) void print();

        int main()
        {
            print();
        }
        ```
5. entrypoint
    - dllDefine.h: 解决dll export 和 import的问题
        ```c++
        #ifdef GE_PLATFORM_WINDOWS // 定义使用的平台
            #ifdef GE_BUILD_DLL // 在ge中定义，而在sandbox中不要定义
                #define GE_API __declspec(dllexport)
            #else
                #define GE_API __declspec(dllimport)
            #endif
        #else
            #error GE only support windows!

        #endif
        ```
    - ge.h: Sandbox应该只需要一个头文件来使用ge
        * 在ge中创建一个ge.h包含所有需要提供给客户的（Sandbox)
        * 在SandBox中的私有属性（C/C++)里面添加头文件路径

    - EntryPoint.h: main函数应该被ge管理，因为资源和内存管理属于engine的工作
        * 通过extern关键字可以保证无需提前知道类型
        * 在SandBox中只需要客户继承Application和实现CreateApplication即可

6. log
    - 通过git管理vendor的module
        * git submodule add link path
        * 再将路径添加到包含路径中即可

7. skip-premake

8. /9 Event system

10. pch: pre-compiled headers
    - 属性- 选择 预编译头文件
    - 可以将代码中非相关的头文件（如memeory、stl等）的包含省略

11. Windows and GLFW
    - 第三方库需要编译的（即需要一个sln）构建lib进行链接的方法
        - 使用premake之类的工具
        - 使用库本身的cmake创建出该库本身的sln，再拷贝其中的projct项目文件，添加到自己项目中，修改头文件输出文件等，再添加引用即可。

        - tips: 一个桌面应用程序通过：main -> app -> window 的架构进行设计

12. Window event
    - 调用路线：
        * 通过application类中设定OnEvent
        * 在windows中维护一个windowdata成员，设定其中的callback为OnEvent
        * 在windows中设定glfw window的user指针指向windowData
        * 设定glfw中window的callback
        

13. layer


14. glad 

15. imgui


