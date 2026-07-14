# ElaWidgetTools 使用文档

本文档介绍 ElaWidgetTools 各组件的用途、基本用法与常用 API, 按功能分类组织。
全部内容依据仓库源码 (头文件、实现与 ElaWidgetToolsExample 示例工程) 整理, 共覆盖 125 个组件与全局服务。
API 完整签名列表见 [doc/API.md](API.md)。

## 目录

- [简介与快速开始](#简介与快速开始)
  - [1. 简介](#1-简介)
  - [2. 环境要求](#2-环境要求)
  - [3. 构建与集成](#3-构建与集成)
  - [4. 快速开始](#4-快速开始)
  - [5. 主题系统](#5-主题系统)
  - [6. 图标](#6-图标)
- [框架与全局服务](#框架与全局服务)
  - [ElaApplication](#elaapplication)
  - [ElaTheme](#elatheme)
  - [ElaWindow](#elawindow)
  - [ElaAppBar](#elaappbar)
  - [ElaWidget](#elawidget)
  - [ElaIcon](#elaicon)
  - [ElaLog](#elalog)
  - [ElaEvent](#elaevent)
  - [ElaNavigationRouter](#elanavigationrouter)
  - [ElaRouter](#elarouter)
- [按钮](#按钮)
  - [ElaPushButton](#elapushbutton)
  - [ElaIconButton](#elaiconbutton)
  - [ElaToolButton](#elatoolbutton)
  - [ElaSplitButton](#elasplitbutton)
  - [ElaDropDownButton](#eladropdownbutton)
  - [ElaToggleButton](#elatogglebutton)
  - [ElaToggleSwitch](#elatoggleswitch)
  - [ElaFloatButton](#elafloatbutton)
  - [ElaCopyButton](#elacopybutton)
- [基础输入](#基础输入)
  - [ElaLineEdit](#elalineedit)
  - [ElaPasswordBox](#elapasswordbox)
  - [ElaPlainTextEdit](#elaplaintextedit)
  - [ElaSpinBox](#elaspinbox)
  - [ElaDoubleSpinBox](#eladoublespinbox)
  - [ElaNumberBox](#elanumberbox)
  - [ElaSlider](#elaslider)
  - [ElaCheckBox](#elacheckbox)
  - [ElaRadioButton](#elaradiobutton)
- [高级输入](#高级输入)
  - [ElaComboBox](#elacombobox)
  - [ElaMultiSelectComboBox](#elamultiselectcombobox)
  - [ElaAutoComplete](#elaautocomplete)
  - [ElaSuggestBox](#elasuggestbox)
  - [ElaTreeSelect](#elatreeselect)
  - [ElaKeyBinder](#elakeybinder)
  - [ElaCaptcha](#elacaptcha)
  - [ElaRatingControl](#elaratingcontrol)
  - [ElaSelectorBar](#elaselectorbar)
  - [ElaTransfer](#elatransfer)
  - [ElaEmojiPicker](#elaemojipicker)
  - [ElaUploadArea](#elauploadarea)
- [日期与滚轮选择](#日期与滚轮选择)
  - [ElaCalendar](#elacalendar)
  - [ElaCalendarPicker](#elacalendarpicker)
  - [ElaRoller](#elaroller)
  - [ElaRollerPicker](#elarollerpicker)
- [数据展示: 状态与进度](#数据展示-状态与进度)
  - [ElaText](#elatext)
  - [ElaInfoBadge](#elainfobadge)
  - [ElaTag](#elatag)
  - [ElaPersonPicture](#elapersonpicture)
  - [ElaStatCard](#elastatcard)
  - [ElaProgressBar](#elaprogressbar)
  - [ElaProgressRing](#elaprogressring)
  - [ElaSteps](#elasteps)
  - [ElaTimeline](#elatimeline)
  - [ElaSkeleton](#elaskeleton)
- [数据展示: 富内容](#数据展示-富内容)
  - [ElaDivider](#eladivider)
  - [ElaLCDNumber](#elalcdnumber)
  - [ElaCountdown](#elacountdown)
  - [ElaQRCode](#elaqrcode)
  - [ElaDashboardGauge](#eladashboardgauge)
  - [ElaChatBubble](#elachatbubble)
  - [ElaMarkdownViewer](#elamarkdownviewer)
  - [ElaCodeEditor](#elacodeeditor)
  - [ElaTerminalWidget](#elaterminalwidget)
  - [ElaWatermark](#elawatermark)
- [卡片](#卡片)
  - [ElaAcrylicUrlCard](#elaacrylicurlcard)
  - [ElaImageCard](#elaimagecard)
  - [ElaInteractiveCard](#elainteractivecard)
  - [ElaPopularCard](#elapopularcard)
  - [ElaPromotionCard](#elapromotioncard)
  - [ElaPromotionView](#elapromotionview)
  - [ElaReminderCard](#elaremindercard)
- [导航与菜单](#导航与菜单)
  - [ElaNavigationBar](#elanavigationbar)
  - [ElaBreadcrumbBar](#elabreadcrumbbar)
  - [ElaPivot](#elapivot)
  - [ElaTabBar](#elatabbar)
  - [ElaTabWidget](#elatabwidget)
  - [ElaMenu](#elamenu)
  - [ElaMenuBar](#elamenubar)
  - [ElaCommandBar](#elacommandbar)
  - [ElaToolBar](#elatoolbar)
  - [ElaStatusBar](#elastatusbar)
  - [ElaDockWidget](#eladockwidget)
- [容器与布局](#容器与布局)
  - [ElaRibbonBar](#elaribbonbar)
  - [ElaRibbonTabBar](#elaribbontabbar)
  - [ElaRibbonGroup](#elaribbongroup)
  - [ElaExpander](#elaexpander)
  - [ElaDrawerArea](#eladrawerarea)
  - [ElaGroupBox](#elagroupbox)
  - [ElaWizard](#elawizard)
  - [ElaFlowLayout](#elaflowlayout)
- [滚动与分页](#滚动与分页)
  - [ElaScrollArea](#elascrollarea)
  - [ElaScrollBar](#elascrollbar)
  - [ElaScrollPage](#elascrollpage)
  - [ElaScrollPageArea](#elascrollpagearea)
  - [ElaSplitter](#elasplitter)
  - [ElaPagination](#elapagination)
  - [ElaVirtualList](#elavirtuallist)
- [对话框与浮层](#对话框与浮层)
  - [ElaContentDialog](#elacontentdialog)
  - [ElaDialog](#eladialog)
  - [ElaMessageDialog](#elamessagedialog)
  - [ElaInputDialog](#elainputdialog)
  - [ElaColorDialog](#elacolordialog)
  - [ElaSheetPanel](#elasheetpanel)
  - [ElaFlyout](#elaflyout)
  - [ElaPopconfirm](#elapopconfirm)
  - [ElaTeachingTip](#elateachingtip)
  - [ElaToolTip](#elatooltip)
- [消息与通知](#消息与通知)
  - [ElaMessageBar](#elamessagebar)
  - [ElaMessageButton](#elamessagebutton)
  - [ElaInfoBar](#elainfobar)
  - [ElaToast](#elatoast)
  - [ElaSnackbar](#elasnackbar)
  - [ElaNotificationCenter](#elanotificationcenter)
  - [ElaSpotlight](#elaspotlight)
  - [ElaSplashScreen](#elasplashscreen)
- [视图与模型](#视图与模型)
  - [ElaListView](#elalistview)
  - [ElaTableView](#elatableview)
  - [ElaTableWidget](#elatablewidget)
  - [ElaTreeView](#elatreeview)
- [图形与屏幕采集](#图形与屏幕采集)
  - [ElaGraphicsView](#elagraphicsview)
  - [ElaGraphicsScene](#elagraphicsscene)
  - [ElaGraphicsItem](#elagraphicsitem)
  - [ElaGraphicsLineItem](#elagraphicslineitem)
  - [ElaDxgiManager](#eladxgimanager)
  - [ElaScreenCaptureManager](#elascreencapturemanager)

## 简介与快速开始

### 1. 简介

ElaWidgetTools 是一个基于 Qt Widget 开发的 FluentUI 风格组件库，本仓库基于 [Liniyous/ElaWidgetTools](https://github.com/Liniyous/ElaWidgetTools) 独立修改发展而来。

- 组件规模：100+ 个公开组件，涵盖基础设施（`ElaApplication` / `ElaTheme` / `ElaWindow`）、按钮与输入、数据展示、卡片、导航与布局、弹出与交互、窗口与面板、视图、编辑器与渲染、聊天与终端、系统功能等类别。完整组件清单见仓库 `README.md`，完整 API 文档见 `doc/API.md`。
- 视觉风格：遵循 FluentUI 设计语言，内置 Light / Dark 双主题，全部组件跟随 `ElaTheme` 主题切换，并附带 3200+ FluentUI 图标（`ElaIconType::IconName` 枚举）。
- 支持平台：Windows、Ubuntu/Kylin、macOS。Windows 下额外提供 `ElaDxgiManager`（DXGI 屏幕采集），macOS 下提供 `ElaScreenCaptureManager`（ScreenCaptureKit 屏幕采集）。
- 版本：CMake 包版本为 2.0.0（`ElaWidgetTools/CMakeLists.txt` 中 `project(ElaWidgetTools VERSION 2.0.0)`），头文件 `ElaDef.h` 中 `ElaDefVersion` 为 "2.0.2"。
- 许可证：MIT，但要求所有分发的软件中必须保留本项目的 MIT 授权许可。

仓库顶层为聚合工程 `ElaFramework`，构建涉及的主要子目录：

| 子目录 | 说明 |
|--------|------|
| `ElaWidgetTools` | 组件库本体，CMake 目标名为 `ElaWidgetTools` |
| `ElaWidgetToolsExample` | 示例程序，展示全部组件用法 |
| `bindings` | 可选的 PySide6/Shiboken6 Python 绑定（由 `BUILD_PYTHON_BINDINGS` 控制） |

### 2. 环境要求

| 项目 | 要求 |
|------|------|
| CMake | 3.10 及以上（`cmake_minimum_required(VERSION 3.10...3.30)`） |
| C++ 标准 | C++17（`CMAKE_CXX_STANDARD 17`，MSVC 自动附加 `/utf-8`） |
| Qt | Qt5 或 Qt6，需要 `Widgets` 模块；Qt 6.x 额外需要 `WidgetsPrivate` 私有模块（构建脚本自动 `find_package`） |
| 构建类型 | 仅允许 `Release` 与 `RelWithDebInfo`，`Debug` 与 `MinSizeRel` 在 configure 阶段直接报错 |

Qt 版本建议（来自根 `CMakeLists.txt` 与 `README.md`）：

- 不推荐版本：Qt 6.5.3 至 Qt 6.6.1，可能出现使用时异常或崩溃，configure 时会输出警告；Qt 6.11.0 在 Windows 上存在 Popup 窗口透明区域合成行为变更的 bug，导致使用 `drawEffectShadow` 绘制阴影的组件出现透明边框（macOS 不受影响），该问题已在 Qt 下一版本修复，本项目通过 `Q_OS_WIN && QT_VERSION_CHECK(6, 11, 0)` 条件编译做了适配，但仍建议改用其他版本。

Qt 路径配置方式（优先级从高到低，见根 `CMakeLists.txt`）：

1. 命令行 `-DQT_SDK_DIR=/path/to/Qt/6.x.x/xxx`
2. 命令行或环境变量 `CMAKE_PREFIX_PATH`（Qt Creator / CLion 默认方式）
3. 直接修改根 `CMakeLists.txt` 中的默认值（当前默认值为 `D:/Qt/6.10.3/msvc2022_64`）

### 3. 构建与集成

#### 3.1 构建仓库自带工程

```bash
git clone <仓库地址>
cd ElaWidgetTools
cmake -B build -DCMAKE_PREFIX_PATH=/path/to/Qt/6.6.3/xxx
cmake --build build --config Release
cmake --build build --target install
```

安装前缀被根 `CMakeLists.txt` 强制固定为仓库根目录下的 `Install/`（`SET(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR}/Install CACHE PATH "Installation path" FORCE)`），安装后目录布局：

```
Install/
├── ElaWidgetTools/
│   ├── include/                 # 全部公开头文件
│   ├── lib/                     # 库文件
│   └── lib/cmake/               # ElaWidgetToolsConfig.cmake / ElaWidgetToolsConfigVersion.cmake / ElaWidgetToolsTargets.cmake
└── ElaWidgetToolsExample/       # 部署完成的示例程序（Windows 下自动执行 windeployqt）
```

示例程序 `ElaWidgetToolsExample` 随工程一同构建，安装后可直接运行，用于浏览全部组件效果。

#### 3.2 相关 CMake 变量与 option

以下名称均来自仓库实际 CMake 文件：

| 名称 | 位置 | 默认值 | 说明 |
|------|------|--------|------|
| `ELAWIDGETTOOLS_BUILD_STATIC_LIB` | `ElaWidgetTools/CMakeLists.txt` | `ON`（FORCE） | `ON` 构建静态库（`STATIC`），`OFF` 构建动态库（`SHARED`）。注意：当前写法为 `set(ELAWIDGETTOOLS_BUILD_STATIC_LIB ON CACHE BOOL "Build static library" FORCE)`，`FORCE` 会在每次 configure 时覆盖命令行传入的 `-DELAWIDGETTOOLS_BUILD_STATIC_LIB=OFF`。如需构建动态库，直接修改该行的 `ON` 为 `OFF` |
| `BUILD_PYTHON_BINDINGS` | 根 `CMakeLists.txt` | `OFF` | `option(BUILD_PYTHON_BINDINGS "Build PySide6/Shiboken6 Python bindings" OFF)`，开启后进入 `bindings` 子目录构建 Python 绑定 |
| `BUILD_ELAPACKETIO` | 根 `CMakeLists.txt` | `OFF`（FORCE） | Windows 专用的 ElaPacketIO 模块开关，当前被 FORCE 固定为 `OFF` |
| `QT_SDK_DIR` | 根 `CMakeLists.txt` | `D:/Qt/6.10.3/msvc2022_64` | Qt SDK 路径，优先级高于 `CMAKE_PREFIX_PATH` |

库目标在 Windows 下额外链接 `D3D11` 与 `DXGI`，在 macOS 下额外链接 `ApplicationServices` 与 `ScreenCaptureKit` 框架，均已在库的 CMake 中以 `PUBLIC` 方式声明，使用方无需手动处理。

#### 3.3 集成方式一：add_subdirectory

将仓库中的 `ElaWidgetTools` 子目录（库本体）以拷贝或 git submodule 方式放入你的工程，然后：

```cmake
cmake_minimum_required(VERSION 3.10)
project(HelloEla LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 库子目录自身未开启 AUTOMOC/AUTORCC, 必须在 add_subdirectory 之前由使用方开启,
# 否则库内的 Q_OBJECT 类和 ElaWidgetTools.qrc 资源无法正常处理
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

# 引入组件库, 目标名为 ElaWidgetTools
add_subdirectory(ElaWidgetTools)

add_executable(HelloEla main.cpp)
target_link_libraries(HelloEla PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    ElaWidgetTools
)
```

说明：

- 头文件搜索路径由目标 `ElaWidgetTools` 通过 `target_include_directories` 的 `BUILD_INTERFACE` 导出，链接目标后即可直接 `#include "ElaWindow.h"`。
- `ElaWidgetTools/CMakeLists.txt` 会将 `CMAKE_CONFIGURATION_TYPES` 强制设为 `Release;RelWithDebInfo`，且 `CMAKE_BUILD_TYPE` 为 `Debug` 或 `MinSizeRel` 时直接 `FATAL_ERROR`。如需 Debug 构建整个工程，需修改该文件开头的构建类型限制。
- Qt 6.x 下库会自行 `find_package(Qt6 REQUIRED COMPONENTS WidgetsPrivate)`，使用方无需额外操作。

#### 3.4 集成方式二：安装后 find_package

先按 3.1 节完成构建与安装，再在你的工程中：

```cmake
cmake_minimum_required(VERSION 3.10)
project(HelloEla LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)

# ElaWidgetToolsConfig.cmake 未调用 find_dependency,
# 必须先由使用方自行查找 Qt, 否则导入目标引用的 Qt 目标不存在
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
if (QT_VERSION_MAJOR EQUAL 6)
    # 静态库的链接接口中包含 Qt6::WidgetsPrivate, 使用方需要一并查找
    set(QT_NO_PRIVATE_MODULE_WARNING ON)
    find_package(Qt6 REQUIRED COMPONENTS WidgetsPrivate)
endif ()

# 指向安装目录中 ElaWidgetToolsConfig.cmake 所在路径,
# 也可以改为在命令行传入 -DElaWidgetTools_DIR=...
set(ElaWidgetTools_DIR "/path/to/ElaWidgetTools/Install/ElaWidgetTools/lib/cmake")
find_package(ElaWidgetTools REQUIRED)

add_executable(HelloEla main.cpp)
target_link_libraries(HelloEla PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    ElaWidgetTools
)
```

`find_package(ElaWidgetTools)` 成功后：

- 导入目标 `ElaWidgetTools` 可直接链接，头文件目录（`<安装前缀>/ElaWidgetTools/include`）已随导入目标导出，无需手动 `include_directories`。
- 同时提供变量 `ElaWidgetTools_LIBRARIES`、`ElaWidgetTools_INCLUDE_DIRS`、`ElaWidgetTools_LIBRARY_DIRS`（定义见 `ElaWidgetToolsConfig.cmake.in`），供传统变量风格的工程使用。

### 4. 快速开始

以下是一个完整可编译的最小程序，初始化流程与示例工程 `ElaWidgetToolsExample/main.cpp` 一致：先创建 `QApplication`，再调用 `eApp->init()` 初始化 `ElaApplication` 单例，最后创建 `ElaWindow` 并通过 `addPageNode` 添加导航页面。

`main.cpp`：

```cpp
#include <QApplication>

#include "ElaApplication.h"
#include "ElaText.h"
#include "ElaWindow.h"

int main(int argc, char* argv[])
{
#if (QT_VERSION < QT_VERSION_CHECK(6, 0, 0))
    // Qt5 需要手动开启高分屏支持, Qt6 默认开启
    QGuiApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
#if (QT_VERSION >= QT_VERSION_CHECK(5, 14, 0))
    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication::setHighDpiScaleFactorRoundingPolicy(Qt::HighDpiScaleFactorRoundingPolicy::PassThrough);
#endif
#endif
    QApplication a(argc, argv);

    // 初始化 ElaApplication 单例(eApp 是 ElaApplication::getInstance() 的宏)
    // 必须在创建任何 Ela 组件之前调用
    eApp->init();

    // 创建带侧边导航栏的无边框主窗口
    ElaWindow w;
    w.setWindowTitle("HelloEla");
    w.resize(1200, 740);

    // 导航栏顶部的用户信息卡(可选)
    w.setUserInfoCardTitle("HelloEla");
    w.setUserInfoCardSubTitle("第一个 ElaWidgetTools 程序");

    // 创建首页页面, 任意 QWidget 均可作为导航页面
    ElaText* homePage = new ElaText("Hello, ElaWidgetTools!", &w);
    homePage->setTextPixelSize(32);
    homePage->setAlignment(Qt::AlignCenter);

    // 将页面加入侧边导航栏, 第三个参数为 FluentUI 图标枚举
    w.addPageNode("Home", homePage, ElaIconType::House);

    // 再添加一个页面
    ElaText* aboutPage = new ElaText("About Page", &w);
    aboutPage->setTextPixelSize(32);
    aboutPage->setAlignment(Qt::AlignCenter);
    w.addPageNode("About", aboutPage, ElaIconType::User);

    // 窗口居中显示
    w.moveToCenter();
    w.show();
    return a.exec();
}
```

配套 CMake 使用第 3.3 或 3.4 节的片段即可。运行后可以看到带侧边导航栏和标题栏的 FluentUI 风格窗口，标题栏自带主题切换按钮。

导航相关 API 补充（均为 `ElaWindow` 成员，签名见 `ElaWindow.h`）：

- `addPageNode(const QString& pageTitle, QWidget* page, ElaIconType::IconName awesome)`：添加页面节点，另有带 `targetExpanderKey`（挂到指定折叠节点下）和 `keyPoints`（角标数字）的重载。
- `addExpanderNode(const QString& expanderTitle, QString& expanderKey, ElaIconType::IconName awesome)`：添加可折叠的分组节点，`expanderKey` 为输出参数，供后续挂载子节点使用。
- `addFooterNode(const QString& footerTitle, QWidget* page, QString& footerKey, int keyPoints, ElaIconType::IconName awesome)`：添加导航栏底部节点（如设置页）。
- `navigation(QString pageKey)`：编程式跳转到指定页面，页面的 key 可通过 `page->property("ElaPageKey").toString()` 获取。

### 5. 主题系统

`ElaTheme` 是全局主题管理器单例，`ElaTheme.h` 提供宏 `eTheme` 作为 `ElaTheme::getInstance()` 的简写。主题模式由 `ElaThemeType::ThemeMode` 枚举表示，取值为 `ElaThemeType::Light` 与 `ElaThemeType::Dark`（定义见 `ElaDef.h`）。

```cpp
#include "ElaTheme.h"

// 切换到深色主题, 所有 Ela 组件自动跟随
eTheme->setThemeMode(ElaThemeType::Dark);

// 读取当前主题模式
ElaThemeType::ThemeMode mode = eTheme->getThemeMode();

// 深浅色互切(示例工程 mainwindow.cpp 中的写法)
eTheme->setThemeMode(eTheme->getThemeMode() == ElaThemeType::Light
                         ? ElaThemeType::Dark
                         : ElaThemeType::Light);

// 跟随系统深浅色
eTheme->setIsFollowSystemTheme(true);
bool isFollow = eTheme->getIsFollowSystemTheme();

// 监听主题变化, 用于更新自绘内容
QObject::connect(eTheme, &ElaTheme::themeModeChanged,
                 [](ElaThemeType::ThemeMode themeMode) {
                     // 根据 themeMode 重新取色并刷新
                 });
```

主题色读取与覆盖：

```cpp
// ElaThemeColor 宏展开为 eTheme->getThemeColor(themeMode, ElaThemeType::themeColor)
QColor primary = ElaThemeColor(ElaThemeType::Dark, PrimaryNormal);

// 等价的显式调用
const QColor& text = eTheme->getThemeColor(ElaThemeType::Light, ElaThemeType::BasicText);

// 覆盖某个主题色(全局生效)
eTheme->setThemeColor(ElaThemeType::Dark, ElaThemeType::PrimaryNormal, QColor(0x4C, 0xA0, 0xE0));
```

可用的颜色角色由 `ElaThemeType::ThemeColor` 枚举定义（`ElaDef.h`），包括 `PrimaryNormal`、`PrimaryHover`、`PrimaryPress`、`BasicText`、`WindowBase`、`PopupBase`、`StatusDanger` 等。

与窗口相关的两点：

- `ElaWindow` 标题栏内置主题切换按钮（`ElaAppBarType::ThemeChangeButtonHint`），点击即在 Light / Dark 间切换，可通过 `setWindowButtonFlag` 关闭。
- `ElaWindow` 的 `ThemeChangeTime` 属性（`setThemeChangeTime(int)`）控制主题切换时的过渡动画时长。

### 6. 图标

库内置 3200+ FluentUI 图标，全部以枚举形式定义在 `ElaDef.h` 的 `ElaIconType::IconName` 中，例如 `ElaIconType::House`、`ElaIconType::User`、`ElaIconType::GearComplex`。示例工程的 "ElaIcon" 页面可以在线浏览和检索全部图标。

多数组件直接接受 `ElaIconType::IconName` 参数，无需手动构造 `QIcon`：

```cpp
// 导航节点图标
w.addPageNode("Home", homePage, ElaIconType::House);

// 按钮图标(ElaPushButton::setElaIcon)
ElaPushButton* button = new ElaPushButton("确定", this);
button->setElaIcon(ElaIconType::House);

// 纯图标按钮
ElaIconButton* iconButton = new ElaIconButton(ElaIconType::GearComplex, this);
```

需要标准 `QIcon` 对象时（例如用于 Qt 原生控件、`QAction` 或窗口图标），使用 `ElaIcon` 单例的 `getElaIcon` 系列重载（签名见 `ElaIcon.h`）：

```cpp
#include "ElaIcon.h"

// 默认尺寸与颜色
QIcon icon1 = ElaIcon::getInstance()->getElaIcon(ElaIconType::House);

// 指定颜色
QIcon icon2 = ElaIcon::getInstance()->getElaIcon(ElaIconType::House, QColor(0x0E, 0x6F, 0xC1));

// 指定像素尺寸
QIcon icon3 = ElaIcon::getInstance()->getElaIcon(ElaIconType::House, 25);

// 指定像素尺寸与颜色
QIcon icon4 = ElaIcon::getInstance()->getElaIcon(ElaIconType::House, 25, QColor(255, 255, 255));

// 指定像素尺寸与固定宽高(用于生成固定画布大小的图标)
QIcon icon5 = ElaIcon::getInstance()->getElaIcon(ElaIconType::House, 25, 32, 32);

// 指定像素尺寸、固定宽高与颜色
QIcon icon6 = ElaIcon::getInstance()->getElaIcon(ElaIconType::House, 25, 32, 32, QColor(255, 255, 255));
```

图标本质是图标字体渲染，颜色不指定时使用默认色，主题切换时组件内部使用的图标会自动跟随主题变色；通过 `getElaIcon` 手动生成的 `QIcon` 是静态快照，如需跟随主题请在 `ElaTheme::themeModeChanged` 信号中重新生成。

## 框架与全局服务

本章介绍 ElaWidgetTools 的框架级组件与全局服务: 应用初始化、主题、主窗口与标题栏、图标、日志、事件总线和两套路由系统。这些组件多为单例, 贯穿整个应用的生命周期。

### ElaApplication

全局应用服务单例, 负责初始化库资源(图标字体、默认字体、Windows API)并统一管理窗口显示模式(Mica 等特效), 继承自 QObject。任何 Ela 组件使用前都应先完成初始化。可通过宏 `eApp` 访问单例。

**头文件**: `#include "ElaApplication.h"`

**基本用法**:

```cpp
#include <QApplication>
#include "ElaApplication.h"
#include "ElaWindow.h"

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    // 初始化资源、图标字体、默认字体并同步系统主题
    // 必须在创建任何 Ela 窗口/控件之前调用
    eApp->init();

    // 设置全局窗口显示模式为 ElaMica(跨平台的图片 Mica 效果)
    eApp->setWindowDisplayMode(ElaApplicationType::ElaMica);
    // 自定义 Mica 底图
    eApp->setElaMicaImagePath(":/include/Image/MicaBase.png");

    ElaWindow w;
    w.show();
    return a.exec();
}
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `static ElaApplication* getInstance()` | 获取全局单例, 等价于宏 `eApp` |
| `void init()` | 注册资源文件、加载 ElaAwesome 图标字体、设置平台默认字体、初始化 Windows API 并同步系统主题 |
| `void setWindowDisplayMode(ElaApplicationType::WindowDisplayMode)` | 设置全局窗口显示模式: `Normal`、`ElaMica`, Windows 平台额外支持 `Mica`、`MicaAlt`、`Acrylic`、`DWMBlur` |
| `ElaApplicationType::WindowDisplayMode getWindowDisplayMode() const` | 获取当前窗口显示模式 |
| `void setElaMicaImagePath(QString)` | 设置 ElaMica 模式使用的底图路径, 默认 `:/include/Image/MicaBase.png` |
| `QString getElaMicaImagePath() const` | 获取 Mica 底图路径 |
| `void syncWindowDisplayMode(QWidget* widget, bool isSync = true)` | 将任意顶层窗口纳入(或移出)全局显示模式同步列表, Ela 系列窗口已自动调用 |
| `static bool containsCursorToItem(QWidget* item)` | 判断鼠标光标当前是否位于指定控件的全局区域内 |

**信号**:

| 信号 | 说明 |
| --- | --- |
| `void pWindowDisplayModeChanged()` | 窗口显示模式变更, 自绘窗口可借此刷新背景 |
| `void pElaMicaImagePathChanged()` | Mica 底图路径变更 |

**注意**:

- `Mica`、`MicaAlt`、`Acrylic`、`DWMBlur` 四个枚举值仅在 Windows 平台编译。其中原生 `Mica`、`MicaAlt`、`Acrylic` 需要 Windows 11, 低版本系统调用会导致窗口绘制失效, `DWMBlur` 在低版本仍可使用; `ElaMica` 为跨平台的图片模拟实现。
- 官方示例中在窗口显示后通过 `QTimer::singleShot` 延迟设置原生特效, 以确保窗口句柄已创建。

### ElaTheme

全局主题管理单例, 负责明暗主题切换、跟随系统主题以及全套语义化主题色的读写, 继承自 QObject。可通过宏 `eTheme` 访问单例, 通过宏 `ElaThemeColor(themeMode, themeColor)` 快捷取色。

**头文件**: `#include "ElaTheme.h"`

**基本用法**:

```cpp
#include <QWidget>
#include "ElaTheme.h"

void setupTheme(QWidget* page)
{
    // 手动切换到暗色主题
    eTheme->setIsFollowSystemTheme(false);
    eTheme->setThemeMode(ElaThemeType::Dark);

    // 或者跟随系统主题自动切换
    eTheme->setIsFollowSystemTheme(true);

    // 监听主题变化, 刷新自绘控件
    QObject::connect(eTheme, &ElaTheme::themeModeChanged, page, [=](ElaThemeType::ThemeMode themeMode) {
        // 宏展开为 eTheme->getThemeColor(themeMode, ElaThemeType::WindowBase)
        QColor baseColor = ElaThemeColor(themeMode, WindowBase);
        Q_UNUSED(baseColor);
        page->update();
    });

    // 覆盖暗色主题下的主色
    eTheme->setThemeColor(ElaThemeType::Dark, ElaThemeType::PrimaryNormal, QColor(76, 160, 224));
}
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `static ElaTheme* getInstance()` | 获取全局单例, 等价于宏 `eTheme` |
| `void setThemeMode(ElaThemeType::ThemeMode themeMode)` | 设置主题模式: `ElaThemeType::Light` 或 `ElaThemeType::Dark`, 所有 Ela 控件自动跟随 |
| `ElaThemeType::ThemeMode getThemeMode() const` | 获取当前主题模式 |
| `void setIsFollowSystemTheme(bool isFollow)` | 设置是否跟随系统明暗主题 |
| `bool getIsFollowSystemTheme() const` | 获取是否跟随系统主题 |
| `void setThemeColor(ElaThemeType::ThemeMode themeMode, ElaThemeType::ThemeColor themeColor, QColor newColor)` | 覆盖指定主题模式下某个语义色 |
| `const QColor& getThemeColor(ElaThemeType::ThemeMode themeMode, ElaThemeType::ThemeColor themeColor)` | 读取指定主题模式下的语义色 |
| `void drawEffectShadow(QPainter* painter, QRect widgetRect, int shadowBorderWidth, int borderRadius)` | 为自绘控件绘制主题阴影效果 |

**信号**:

| 信号 | 说明 |
| --- | --- |
| `void themeModeChanged(ElaThemeType::ThemeMode themeMode)` | 主题模式变更, 自绘代码应连接此信号刷新配色 |
| `void pIsFollowSystemThemeChanged(bool isFollow)` | 跟随系统主题开关变更 |

**注意**:

- `ElaThemeType::ThemeColor` 枚举定义于 `ElaDef.h`, 包含 `WindowBase`、`BasicText`、`PrimaryNormal`、`PopupBase`、`StatusDanger` 等 40 余项语义色, 自绘控件应从这里取色而不是硬编码颜色。
- 开启 `setIsFollowSystemTheme(true)` 后系统主题变化同样会触发 `themeModeChanged`; 若要手动固定主题, 应先关闭跟随系统。

### ElaWindow

FluentUI 风格的无边框主窗口, 集成 ElaAppBar 标题栏、左侧导航栏、用户信息卡与中央堆栈页面, 继承自 QMainWindow, 是绝大多数应用的顶层窗口。

**头文件**: `#include "ElaWindow.h"`

**基本用法**:

```cpp
#include <QApplication>
#include <QPixmap>
#include "ElaApplication.h"
#include "ElaWindow.h"

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    eApp->init();

    ElaWindow w;
    w.setWindowTitle("Demo");
    w.resize(1200, 740);

    // 用户信息卡(导航栏顶部)
    w.setUserInfoCardTitle("Ela Tool");
    w.setUserInfoCardSubTitle("user@example.com");
    w.setUserInfoCardPixmap(QPixmap(":/Resource/Image/avatar.png"));

    // 添加顶层页面节点
    QWidget* homePage = new QWidget(&w);
    w.addPageNode("HOME", homePage, ElaIconType::House);

    // 添加展开节点与其子页面, key 通过引用参数返回
    QString viewKey;
    w.addExpanderNode("ElaView", viewKey, ElaIconType::CameraViewfinder);
    QWidget* listPage = new QWidget(&w);
    w.addPageNode("ElaListView", listPage, viewKey, ElaIconType::List);

    // 底部设置节点
    QString settingKey;
    QWidget* settingPage = new QWidget(&w);
    w.addFooterNode("Setting", settingPage, settingKey, 0, ElaIconType::GearComplex);

    // 通过 pageKey 主动跳转: 添加页面成功后 key 写入页面的 "ElaPageKey" 属性
    w.navigation(homePage->property("ElaPageKey").toString());

    w.moveToCenter();
    w.show();
    return a.exec();
}
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `void moveToCenter()` | 将窗口移动到屏幕中央 |
| `ElaNavigationType::NodeResult addPageNode(const QString& pageTitle, QWidget* page, ElaIconType::IconName awesome = ElaIconType::None)` | 添加顶层页面节点 |
| `ElaNavigationType::NodeResult addPageNode(const QString& pageTitle, QWidget* page, const QString& targetExpanderKey, ElaIconType::IconName awesome = ElaIconType::None)` | 在指定展开节点下添加子页面 |
| `ElaNavigationType::NodeResult addExpanderNode(const QString& expanderTitle, QString& expanderKey, ElaIconType::IconName awesome = ElaIconType::None) const` | 添加可展开分组节点, 生成的 key 由引用参数带回 |
| `ElaNavigationType::NodeResult addFooterNode(const QString& footerTitle, QWidget* page, QString& footerKey, int keyPoints = 0, ElaIconType::IconName awesome = ElaIconType::None)` | 添加导航栏底部节点, page 传 nullptr 时仅作为按钮使用 |
| `ElaNavigationType::NodeResult addCategoryNode(const QString& categoryTitle, QString& categoryKey)` | 添加分类标题节点 |
| `void navigation(QString pageKey)` | 跳转到指定 pageKey 对应的页面 |
| `void removeNavigationNode(QString nodeKey) const` | 移除导航节点及其子节点 |
| `void setNodeKeyPoints(QString nodeKey, int keyPoints)` | 设置节点右侧的红点角标数字 |
| `void setUserInfoCardVisible(bool isVisible)` | 显示/隐藏用户信息卡, 配套接口还有 `setUserInfoCardTitle(QString)`、`setUserInfoCardSubTitle(QString)`、`setUserInfoCardPixmap(QPixmap)` |
| `void setCustomWidget(ElaAppBarType::CustomArea customArea, QWidget* customWidget, QObject* hitTestObject = nullptr, const QString& hitTestFunctionName = "")` | 在标题栏 `LeftArea`/`MiddleArea`/`RightArea` 区域嵌入自定义控件 |
| `void setCustomMenu(QMenu* customMenu)` | 替换标题栏右键菜单, 传 nullptr 恢复原生菜单 |
| `void addCentralWidget(QWidget* centralWidget)` | 追加一个主堆栈页面, 配合属性 `setCurrentStackIndex(int)` 切换 |
| `void setWindowButtonFlag(ElaAppBarType::ButtonType buttonFlag, bool isEnable = true)` | 启用/禁用标题栏指定按钮, 批量设置用 `setWindowButtonFlags(ElaAppBarType::ButtonFlags)` |
| `void setNavigationBarDisplayMode(ElaNavigationType::NavigationDisplayMode)` | 属性 setter, 导航栏显示模式: `Auto`/`Minimal`/`Compact`/`Maximal` |
| `void setStackSwitchMode(ElaWindowType::StackSwitchMode)` | 属性 setter, 页面切换动画: `None`/`Popup`/`Scale`/`Flip`/`Blur` |
| `void setIsDefaultClosed(bool)` | 属性 setter, 为 false 时点击关闭按钮不关闭窗口, 仅发出 `closeButtonClicked` 信号 |

**信号**:

| 信号 | 说明 |
| --- | --- |
| `void userInfoCardClicked()` | 用户信息卡被点击 |
| `void closeButtonClicked()` | 关闭按钮被点击, 配合 `setIsDefaultClosed(false)` 可实现关闭确认或最小化到托盘 |
| `void navigationNodeClicked(ElaNavigationType::NavigationNodeType nodeType, QString nodeKey)` | 任意导航节点被点击 |
| `void pageOpenInNewWindow(QString nodeKey)` | 页面在新窗口中打开(需开启 `setIsAllowPageOpenInNewWindow(true)`) |

**注意**:

- `centralWidget()` 与 `setCentralWidget()` 已被私有化, 不能像普通 QMainWindow 那样使用; 页面统一通过 `addPageNode` 或 `addCentralWidget` 管理。
- `addPageNode` 成功后会向 page 写入 `"ElaPageKey"` 动态属性, `page->property("ElaPageKey").toString()` 即该页面的导航 key。
- 添加节点的返回值为 `ElaNavigationType::NodeResult`, 底部节点存在数量上限(超限返回 `FooterUpperLimit`), 建议检查返回值。
- 窗口背景可通过属性 `setWindowPaintMode(ElaWindowType::PaintMode)` 切换为图片(`Pixmap`)或动图(`Movie`)模式, 并用 `setWindowPixmap`/`setWindowMoviePath` 按明暗主题分别配置。

### ElaAppBar

无边框窗口标题栏组件, 提供窗口拖动、缩放、双击最大化以及导航/置顶/主题切换/最小化/最大化/关闭等按钮, 在 Windows 上通过接管 nativeEvent 保留原生窗口行为, 继承自 QWidget。ElaWindow、ElaWidget、ElaDialog 均已内置, 仅在自定义无边框窗口时需要手动使用。

**头文件**: `#include "ElaAppBar.h"`

**基本用法**:

```cpp
// mywindow.h
#include <QWidget>
#include "ElaAppBar.h"

class MyWindow : public QWidget
{
    Q_OBJECT
    Q_TAKEOVER_NATIVEEVENT_H // Windows 下声明 nativeEvent 重写, 其他平台展开为空
public:
    explicit MyWindow(QWidget* parent = nullptr);

private:
    ElaAppBar* _appBar{nullptr};
};

// mywindow.cpp
#include "mywindow.h"

// 将原生窗口消息转交给 ElaAppBar 处理(拖拽、贴边、阴影等)
Q_TAKEOVER_NATIVEEVENT_CPP(MyWindow, _appBar)
MyWindow::MyWindow(QWidget* parent)
    : QWidget(parent)
{
    setWindowTitle("自定义无边框窗口");
    resize(800, 600);
    // 构造后自动占据窗口顶部 45px 并接管无边框行为
    _appBar = new ElaAppBar(this);
    // 只保留最小化和关闭按钮
    _appBar->setWindowButtonFlags(ElaAppBarType::MinimizeButtonHint | ElaAppBarType::CloseButtonHint);
    connect(_appBar, &ElaAppBar::closeButtonClicked, this, [=]() {
        // IsDefaultClosed 默认为 true, 窗口会自行关闭; 设为 false 后在此自行处理
    });
}
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `void setCustomWidget(ElaAppBarType::CustomArea customArea, QWidget* customWidget, QObject* hitTestObject = nullptr, const QString& hitTestFunctionName = "")` | 在标题栏指定区域嵌入自定义控件 |
| `QWidget* getCustomWidget(ElaAppBarType::CustomArea customArea) const` | 获取指定区域的自定义控件 |
| `void setCustomMenu(QMenu* customMenu)` | 设置标题栏右键菜单 |
| `void setWindowButtonFlag(ElaAppBarType::ButtonType buttonFlag, bool isEnable = true)` | 启用/禁用单个标题栏按钮 |
| `void setWindowButtonFlags(ElaAppBarType::ButtonFlags buttonFlags)` | 批量设置标题栏按钮组合 |
| `ElaAppBarType::ButtonFlags getWindowButtonFlags() const` | 获取当前按钮组合 |
| `void setRouteBackButtonEnable(bool isEnable)` | 设置路由后退按钮可用性 |
| `void setRouteForwardButtonEnable(bool isEnable)` | 设置路由前进按钮可用性 |
| `void setAppBarHeight(int)` | 属性 setter, 标题栏高度, 默认 45 |
| `void setIsStayTop(bool)` | 属性 setter, 窗口置顶 |
| `void setIsFixedSize(bool)` | 属性 setter, 固定窗口尺寸(禁止拉伸) |
| `void setIsOnlyAllowMinAndClose(bool)` | 属性 setter, 仅允许最小化与关闭(禁用最大化与双击) |
| `void setIsDefaultClosed(bool)` | 属性 setter, 是否默认执行关闭 |

**信号**:

| 信号 | 说明 |
| --- | --- |
| `void routeBackButtonClicked()` / `void routeForwardButtonClicked()` | 路由后退/前进按钮被点击 |
| `void navigationButtonClicked()` | 导航栏展开按钮被点击 |
| `void themeChangeButtonClicked()` | 主题切换按钮被点击 |
| `void closeButtonClicked()` | 关闭按钮被点击 |

**注意**:

- 构造时会把父级顶层窗口设为无边框, 并通过 `setContentsMargins(0, 45, 0, 0)` 为标题栏预留空间, 布局内容时无需再避让。
- Windows 平台必须在窗口类中使用 `Q_TAKEOVER_NATIVEEVENT_H` / `Q_TAKEOVER_NATIVEEVENT_CPP(CLASS, appBar成员)` 宏对转发 nativeEvent, 否则原生拖拽、贴边分屏等行为失效; macOS/Linux 下这两个宏展开为空, 无需额外处理。
- 默认按钮组合为 RouteBack/RouteForward/StayTop/ThemeChange/Minimize/Maximize/Close, 导航按钮默认隐藏。

### ElaWidget

自带 ElaAppBar 标题栏的无边框浮动窗口, 适合做独立工具窗、图片预览窗等次级顶层窗口, 继承自 QWidget, 默认尺寸 500x500, 背景自动跟随主题与全局窗口显示模式。

**头文件**: `#include "ElaWidget.h"`

**基本用法**:

```cpp
#include "ElaWidget.h"

void showPreviewWindow()
{
    ElaWidget* previewWindow = new ElaWidget;
    previewWindow->setAttribute(Qt::WA_DeleteOnClose); // 关闭即销毁
    previewWindow->setWindowTitle("预览窗口");
    // 隐藏置顶按钮, 但让窗口保持置顶
    previewWindow->setWindowButtonFlag(ElaAppBarType::StayTopButtonHint, false);
    previewWindow->setIsStayTop(true);
    previewWindow->resize(800, 600);
    previewWindow->moveToCenter(); // 移动到屏幕中央
    previewWindow->show();
}
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `void moveToCenter()` | 将窗口移动到当前屏幕中央 |
| `void setWindowButtonFlag(ElaAppBarType::ButtonType buttonFlag, bool isEnable = true)` | 启用/禁用单个标题栏按钮 |
| `void setWindowButtonFlags(ElaAppBarType::ButtonFlags buttonFlags)` | 批量设置标题栏按钮组合 |
| `ElaAppBarType::ButtonFlags getWindowButtonFlags() const` | 获取当前按钮组合 |
| `void setIsStayTop(bool)` | 属性 setter, 窗口置顶 |
| `void setIsFixedSize(bool)` | 属性 setter, 固定窗口尺寸 |
| `void setIsDefaultClosed(bool)` | 属性 setter, 为 false 时点击关闭仅发信号不关闭 |
| `void setAppBarHeight(int)` | 属性 setter, 标题栏高度 |
| `int getAppBarHeight() const` | 获取标题栏高度, 计算内容区尺寸时常用 |

**信号**:

| 信号 | 说明 |
| --- | --- |
| `void closeButtonClicked()` | 关闭按钮被点击 |
| `void themeChangeButtonClicked()` | 主题切换按钮被点击 |
| `void routeBackButtonClicked()` / `void navigationButtonClicked()` | 对应标题栏按钮被点击(默认按钮组合中未启用) |

**注意**:

- 默认标题栏按钮组合为 StayTop/Minimize/Maximize/Close。
- 通常以无父对象方式创建作为顶层窗口, 建议配合 `Qt::WA_DeleteOnClose` 管理生命周期。
- 内容布局需从 `getAppBarHeight()` 以下开始, 或直接对 ElaWidget 设置布局(其 contentsMargins 已为标题栏预留空间)。

### ElaIcon

字体图标工厂单例, 将 `ElaIconType::IconName` 枚举(FontAwesome 图标集, 定义于 `ElaDef.h`)渲染为 QIcon, 供任意需要 QIcon 的 Qt 接口使用。普通类(非 QObject), 通过 `getInstance()` 访问。

**头文件**: `#include "ElaIcon.h"`

**基本用法**:

```cpp
#include <QPushButton>
#include "ElaIcon.h"

void setupIcons(QPushButton* button)
{
    // 默认 30x30 画布、25px 字号的图标
    QIcon icon = ElaIcon::getInstance()->getElaIcon(ElaIconType::House);
    // 指定颜色
    QIcon colorIcon = ElaIcon::getInstance()->getElaIcon(ElaIconType::Broom, QColor(220, 60, 60));
    // 指定字号与画布宽高
    QIcon bigIcon = ElaIcon::getInstance()->getElaIcon(ElaIconType::GearComplex, 25, 40, 40);
    Q_UNUSED(colorIcon);
    Q_UNUSED(bigIcon);
    button->setIcon(icon);
}
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `static ElaIcon* getInstance()` | 获取全局单例 |
| `QIcon getElaIcon(ElaIconType::IconName awesome)` | 生成默认尺寸(30x30 画布)的图标 |
| `QIcon getElaIcon(ElaIconType::IconName awesome, QColor iconColor)` | 生成指定颜色的图标 |
| `QIcon getElaIcon(ElaIconType::IconName awesome, int pixelSize)` | 指定字号 |
| `QIcon getElaIcon(ElaIconType::IconName awesome, int pixelSize, QColor iconColor)` | 指定字号与颜色 |
| `QIcon getElaIcon(ElaIconType::IconName awesome, int pixelSize, int fixedWidth, int fixedHeight)` | 指定字号与画布宽高 |
| `QIcon getElaIcon(ElaIconType::IconName awesome, int pixelSize, int fixedWidth, int fixedHeight, QColor iconColor)` | 指定字号、画布宽高与颜色 |

**注意**:

- 图标字体 ElaAwesome.ttf 由 `eApp->init()` 加载, 未初始化时图标无法正常渲染。
- 不指定颜色的重载使用 QPainter 默认画笔(黑色), 生成的 QIcon 不会随主题自动变色; 需要跟随主题时应监听 `ElaTheme::themeModeChanged` 并用主题色重新生成。
- 许多 Ela 控件(如 ElaToolButton 的 `setElaIcon`、ElaMenu 的 `addElaIconAction`)可直接接收 `ElaIconType::IconName`, 无需经过 ElaIcon 转换。

### ElaLog

全局日志单例, 通过 `qInstallMessageHandler` 接管 Qt 的 qDebug/qWarning/qCritical/qInfo/qFatal 输出, 格式化后追加写入日志文件, 同时以信号转发给 UI, 继承自 QObject。

**头文件**: `#include "ElaLog.h"`

**基本用法**:

```cpp
#include <QDebug>
#include <QObject>
#include "ElaLog.h"

void setupLog(QObject* receiver)
{
    // 配置日志文件(默认保存到程序工作目录, 文件名 ElaLog.txt)
    ElaLog::getInstance()->setLogSavePath("D:/logs");
    ElaLog::getInstance()->setLogFileName("MyApp");
    ElaLog::getInstance()->setIsLogFileNameWithTime(true); // 文件名附加启动时间
    // 安装消息处理器, 开始接管 Qt 日志
    ElaLog::getInstance()->initMessageLog(true);

    // 将日志实时转发到界面(如日志列表视图)
    QObject::connect(ElaLog::getInstance(), &ElaLog::logMessage, receiver, [=](QString log) {
        // 在此追加到 UI 模型
        Q_UNUSED(log);
    });

    qDebug() << "这条日志会被写入文件并通过 logMessage 信号转发";
}
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `static ElaLog* getInstance()` | 获取全局单例 |
| `void initMessageLog(bool isEnable)` | true 安装日志处理器, false 恢复 Qt 默认输出 |
| `void setLogSavePath(QString)` | 属性 setter, 日志保存目录, 默认为 `QDir::currentPath()` |
| `QString getLogSavePath() const` | 获取日志保存目录 |
| `void setLogFileName(QString)` | 属性 setter, 日志文件名(不含扩展名), 默认 "ElaLog" |
| `QString getLogFileName() const` | 获取日志文件名 |
| `void setIsLogFileNameWithTime(bool)` | 属性 setter, 文件名是否附加时间戳, 默认 false |
| `bool getIsLogFileNameWithTime() const` | 获取时间戳开关 |

**信号**:

| 信号 | 说明 |
| --- | --- |
| `void logMessage(QString log)` | 每产生一条日志即发出, 携带格式化后的完整日志文本 |

**注意**:

- 日志格式为 `[级别-时间](函数: xxx , 行数: n) -> 内容`, 级别文本为简体中文(信息/警告/错误/提示/致命)。
- 未开启时间戳时, 单例构造以及修改 LogSavePath/LogFileName 属性会清空(截断)目标日志文件, 注意备份历史日志。
- `initMessageLog(true)` 之后所有 qDebug 输出都会走文件写入, 高频日志场景注意 IO 开销。

### ElaEvent

全局事件总线的订阅句柄, 与总线单例 ElaEventBus 一起声明于 `ElaEventBus.h`。ElaEvent 将一个事件名绑定到其 parent 对象的成员函数, ElaEventBus 负责按事件名广播 QVariantMap 数据, 实现无直接依赖的跨组件通信。两者均继承自 QObject。

**头文件**: `#include "ElaEventBus.h"`

**基本用法**:

```cpp
#include <QDebug>
#include <QWidget>
#include "ElaEventBus.h"

// 订阅方: 回调函数必须是 parent 对象上带 QVariantMap 参数的槽函数或 Q_INVOKABLE 方法
class Receiver : public QWidget
{
    Q_OBJECT
public:
    explicit Receiver(QWidget* parent = nullptr)
        : QWidget(parent)
    {
        // 事件 "CustomEvent" 触发时调用 this->onCustomEvent(data)
        ElaEvent* event = new ElaEvent("CustomEvent", "onCustomEvent", this);
        event->registerAndInit();
    }

public Q_SLOTS:
    void onCustomEvent(QVariantMap data)
    {
        qDebug() << "收到事件数据" << data;
    }
};

// 发布方: 任意位置按事件名广播
void publish()
{
    QVariantMap data;
    data.insert("key", "value");
    ElaEventBus::getInstance()->post("CustomEvent", data);
    // 查看当前已注册的事件名列表
    qDebug() << ElaEventBus::getInstance()->getRegisteredEventsName();
}
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `explicit ElaEvent(QString eventName, QString functionName, QObject* parent = nullptr)` | 构造订阅: 事件名 + parent 上的回调函数名 |
| `ElaEventBusType::EventBusReturnType registerAndInit()` | 注册到事件总线, 返回 `Success`/`EventInvalid`/`EventNameInvalid` |
| `void setEventName(QString)` / `QString getEventName() const` | 属性读写, 事件名 |
| `void setFunctionName(QString)` / `QString getFunctionName() const` | 属性读写, 回调函数名 |
| `void setConnectionType(Qt::ConnectionType)` / `Qt::ConnectionType getConnectionType() const` | 属性读写, 回调的连接方式, 默认 `Qt::AutoConnection` |
| `ElaEventBusType::EventBusReturnType ElaEventBus::post(const QString& eventName, const QVariantMap& data = {})` | 广播事件, 依次调用所有订阅者的回调 |
| `QStringList ElaEventBus::getRegisteredEventsName() const` | 获取当前已注册的全部事件名 |
| `static ElaEventBus* ElaEventBus::getInstance()` | 获取事件总线单例 |

**注意**:

- 回调通过 `QMetaObject::invokeMethod` 触发, 函数签名必须能接收一个 `QVariantMap` 参数, 且必须是槽函数或 `Q_INVOKABLE` 方法; parent 为空的 ElaEvent 在 post 时会被跳过。
- ElaEvent 以 parent 管理生命周期, 析构时自动从总线反注册, 无需手动清理。
- 库内部已占用事件名 `"WMWindowClicked"`(标题栏鼠标事件广播), 自定义事件应避免同名。

### ElaNavigationRouter

全局导航历史路由单例, 以历史栈方式记录导航操作并支持后退/前进回放, ElaWindow 与 ElaScrollPage 的页面跳转已自动接入, 继承自 QObject。适合实现浏览器式的后退/前进按钮。

**头文件**: `#include "ElaNavigationRouter.h"`

**基本用法**:

```cpp
#include <QVariantMap>
#include "ElaNavigationRouter.h"
#include "ElaToolButton.h"

void setupRouteButtons(ElaToolButton* backButton, ElaToolButton* forwardButton)
{
    // 后退 / 前进
    QObject::connect(backButton, &ElaToolButton::clicked, backButton, [=]() {
        ElaNavigationRouter::getInstance()->navigationRouteBack();
    });
    QObject::connect(forwardButton, &ElaToolButton::clicked, forwardButton, [=]() {
        ElaNavigationRouter::getInstance()->navigationRouteForward();
    });

    // 根据路由状态刷新按钮可用性
    QObject::connect(ElaNavigationRouter::getInstance(), &ElaNavigationRouter::navigationRouterStateChanged,
                     backButton, [=](ElaNavigationRouterType::RouteMode routeMode) {
        switch (routeMode)
        {
        case ElaNavigationRouterType::BackValid: backButton->setEnabled(true); break;
        case ElaNavigationRouterType::BackInvalid: backButton->setEnabled(false); break;
        case ElaNavigationRouterType::ForwardValid: forwardButton->setEnabled(true); break;
        case ElaNavigationRouterType::ForwardInvalid: forwardButton->setEnabled(false); break;
        }
    });
}

// 记录自定义路由点: 回退/前进时会通过元对象系统回调 routeObject 上的函数
void recordRoute(QObject* routeObject)
{
    QVariantMap routeData;
    routeData.insert("page", "home");
    ElaNavigationRouter::getInstance()->navigationRoute(routeObject, "onNavigationRoute", routeData);
}
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `static ElaNavigationRouter* getInstance()` | 获取全局单例 |
| `ElaNavigationRouterType::NavigationRouteType navigationRoute(QObject* routeObject, QString routeFunctionName, const QVariantMap& routeData = {}, Qt::ConnectionType connectionType = Qt::AutoConnection)` | 记录一个路由点, 返回 `Success`/`ObjectInvalid`/`FunctionNameInvalid` |
| `void navigationRouteBack()` | 后退: 回调当前记录的函数并携带 routeData |
| `void navigationRouteForward()` | 前进: 回调下一条记录的函数 |
| `void clearNavigationRoute()` | 清空全局导航历史 |
| `ElaNavigationRouterType::NavigationRouteType navigationRoute(QObject* context, QObject* routeObject, QString routeFunctionName, const QVariantMap& routeData = {}, Qt::ConnectionType connectionType = Qt::AutoConnection)` | 按 context(通常为窗口)记录独立历史的重载 |
| `void navigationRouteBack(QObject* context)` / `void navigationRouteForward(QObject* context)` | 指定 context 的后退/前进 |
| `void clearNavigationRoute(QObject* context)` | 清空指定 context 的历史 |
| `void setMaxRouteCount(int)` / `int getMaxRouteCount() const` | 属性读写, 历史栈容量上限, 默认 25 |

**信号**:

| 信号 | 说明 |
| --- | --- |
| `void navigationRouterStateChanged(ElaNavigationRouterType::RouteMode routeMode)` | 全局历史的后退/前进可用性变化: `BackValid`/`BackInvalid`/`ForwardValid`/`ForwardInvalid` |
| `void windowRouterStateChanged(QObject* context, ElaNavigationRouterType::RouteMode routeMode)` | 指定 context 独立历史的状态变化 |

**注意**:

- 回调时会向 routeData 注入 `"ElaRouteBackMode"` 键(后退为 true, 前进为 false), 回调函数可据此区分方向; 回调函数必须是 routeObject 上带 `QVariantMap` 参数的槽函数或 `Q_INVOKABLE` 方法。
- 历史记录超过 MaxRouteCount 时最早的记录被丢弃; 在历史中间位置记录新路由点会截断其后的前进记录。
- 与 ElaRouter 的分工: ElaNavigationRouter 是操作历史栈(后退/前进), ElaRouter 是声明式路由表(按路径导航), 两者可同时使用。

### ElaRouter

Vue Router 风格的声明式路由单例(宏 `eRouter`), 以路径为键注册页面工厂并安装到 ElaWindow 导航栏, 支持懒加载、路由守卫、动态路由与路由元信息, 继承自 QObject。

**头文件**: `#include "ElaRouter.h"`

**基本用法**:

```cpp
#include <QVBoxLayout>
#include "ElaRouter.h"
#include "ElaWindow.h"

void setupRouter(ElaWindow* window)
{
    // 1. 绑定目标主窗口(必须先于其他操作)
    eRouter->bindWindow(window);

    // 2. 注册路由表: 父路由 + 懒加载子页面
    eRouter->addRoutes({
        {
            "/demo", "路由演示", ElaIconType::Route, {}, nullptr,
            {
                {
                    "/page-a", "页面 A", ElaIconType::FileLines,
                    {{"keepAlive", true}}, // meta 元信息
                    []() -> QWidget* {
                        // 懒加载工厂: 首次导航到该路径时才实例化
                        QWidget* page = new QWidget();
                        new QVBoxLayout(page);
                        return page;
                    }
                },
            }
        },
    });
    // 3. 安装到 ElaWindow 导航栏
    eRouter->installRoutes();

    // 4. 全局前置守卫: 返回 false 拦截本次跳转
    eRouter->beforeEach([](const QString& to, const QString& from, const QVariantMap& params) -> bool {
        QVariantMap meta = eRouter->getRouteMeta(to);
        return meta.value("role").toString() != "admin"; // 拦截 admin 页面
    });

    // 5. 代码导航
    ElaRouterType::NavigationResult result = eRouter->push("/demo/page-a", {{"from", "code"}});
    if (result == ElaRouterType::GuardRejected)
    {
        // 被守卫拦截
    }
}
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `void bindWindow(ElaWindow* window)` | 绑定路由生效的主窗口, 未绑定时导航返回 `WindowNotBound` |
| `ElaRouterType::NavigationResult addRoute(const ElaRouteConfig& config)` | 注册单条路由(可含 children 子路由) |
| `ElaRouterType::NavigationResult addRoutes(const QVector<ElaRouteConfig>& configs)` | 批量注册路由 |
| `ElaRouterType::NavigationResult addDynamicRoute(const QString& parentPath, const ElaRouteConfig& config)` | 运行时向已有父路由追加子路由 |
| `ElaRouterType::NavigationResult removeRoute(const QString& path)` | 移除指定路径的路由 |
| `void installRoutes()` | 将路由表安装到绑定窗口的导航栏 |
| `ElaRouterType::NavigationResult push(const QString& path, const QVariantMap& params = {})` | 导航到指定路径并压入历史 |
| `ElaRouterType::NavigationResult replace(const QString& path, const QVariantMap& params = {})` | 导航并替换当前历史记录 |
| `void back()` / `void forward()` | 路由历史后退/前进 |
| `QString getCurrentPath() const` / `QVariantMap getCurrentParams() const` | 获取当前路径与参数 |
| `int beforeEach(const ElaRouteGuard& guard)` | 注册全局前置守卫, 返回守卫 id, 用 `removeBeforeGuard(int guardId)` 移除 |
| `int afterEach(const ElaRouteAfterHook& hook)` | 注册全局后置钩子, 用 `removeAfterHook(int hookId)` 移除 |
| `void setRouteBeforeEnter(const QString& path, const ElaRouteGuard& guard)` | 为单条路由设置独享的进入守卫 |
| `bool hasRoute(const QString& path) const` / `QStringList getRoutePaths() const` / `QVariantMap getRouteMeta(const QString& path) const` | 路由表查询 |
| `void resetRouter()` | 清空路由表、当前路径/参数与全部守卫和钩子, 不清空导航历史, 也不解除窗口绑定 |

**信号**:

| 信号 | 说明 |
| --- | --- |
| `void routeChanged(const QString& path, const QVariantMap& params)` | 路由跳转完成 |
| `void navigationBlocked(const QString& path)` | 跳转被守卫拦截 |
| `void routeTableChanged()` | 路由表增删变化 |

**注意**:

- 调用顺序固定为 `bindWindow` -> `addRoutes` -> `installRoutes`, 之后才能 `push`; 未绑定窗口时所有导航返回 `ElaRouterType::WindowNotBound`。
- 子路由的完整路径为父路径拼接子路径, 例如父 `"/demo"` 下的 `"/page-a"` 实际路径是 `"/demo/page-a"`。
- `ElaRouteConfig` 字段: `path`(路径)、`title`(导航栏标题)、`icon`(图标)、`meta`(元信息 QVariantMap)、`factory`(页面工厂, 懒加载)、`children`(子路由)、`keyPoints`(角标数字); 父路由 factory 可为 nullptr, 表现为展开分组。
- 守卫 `ElaRouteGuard` 签名为 `bool(const QString& to, const QString& from, const QVariantMap& params)`, 返回 false 拦截; 导航结果枚举 `ElaRouterType::NavigationResult` 包含 `Success`/`RouteNotFound`/`GuardRejected`/`FactoryFailed`/`WindowNotBound`/`RouteAlreadyExists`/`ParentRouteNotFound`。

## 按钮

### ElaPushButton

标准的 FluentUI 风格按钮, 支持明暗主题下分别配置背景色与文本色, 可附带 ElaAwesome 图标, 是最常用的通用按钮。继承自 QPushButton, clicked() 等信号照常可用。

**头文件**: `#include "ElaPushButton.h"`

**基本用法**:

```cpp
#include <QHBoxLayout>
#include <QWidget>

#include "ElaPushButton.h"

void createPushButtons(QWidget* parent, QHBoxLayout* layout)
{
    // 纯文本按钮
    ElaPushButton* button = new ElaPushButton("确定", parent);
    QObject::connect(button, &ElaPushButton::clicked, parent, [=]() {
        // 点击后的业务逻辑
    });

    // 带图标按钮: 图标为 ElaAwesome 字体图标, 第二个参数为图标像素大小
    ElaPushButton* iconButton = new ElaPushButton("带图标按钮", parent);
    iconButton->setElaIcon(ElaIconType::Heart, 16);
    iconButton->setHoverEnabled(false); // 关闭悬停高亮效果
    iconButton->setFixedSize(130, 38);

    // 自定义颜色按钮: 明暗主题分别设置
    ElaPushButton* colorButton = new ElaPushButton("警告操作", parent);
    colorButton->setBorderRadius(6);
    colorButton->setLightDefaultColor(QColor(0xE8, 0x11, 0x23));
    colorButton->setDarkDefaultColor(QColor(0xE8, 0x11, 0x23));
    colorButton->setLightTextColor(Qt::white);
    colorButton->setDarkTextColor(Qt::white);

    layout->addWidget(button);
    layout->addWidget(iconButton);
    layout->addWidget(colorButton);
}
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `explicit ElaPushButton(QString text, QWidget* parent = nullptr)` | 以文本构造按钮 |
| `void setBorderRadius(int BorderRadius)` / `int getBorderRadius() const` | 圆角半径, 默认 3 |
| `void setLightDefaultColor(QColor LightDefaultColor)` | 浅色主题下的默认背景色 |
| `void setDarkDefaultColor(QColor DarkDefaultColor)` | 深色主题下的默认背景色 |
| `void setLightHoverColor(QColor LightHoverColor)` / `void setDarkHoverColor(QColor DarkHoverColor)` | 明暗主题下的悬停背景色 |
| `void setLightPressColor(QColor LightPressColor)` / `void setDarkPressColor(QColor DarkPressColor)` | 明暗主题下的按下背景色 |
| `void setLightTextColor(QColor color)` / `void setDarkTextColor(QColor color)` | 明暗主题下的文本颜色 |
| `void setElaIcon(ElaIconType::IconName icon)` | 设置 ElaAwesome 图标, 图标显示在文本左侧 |
| `void setElaIcon(ElaIconType::IconName icon, int iconSize)` | 设置图标并指定图标像素大小 |
| `void setHoverEnabled(bool enabled)` / `bool isHoverEnabled() const` | 是否启用悬停高亮效果 |

**信号**:

- `void clicked(bool checked = false)`: 继承自 QAbstractButton, 点击时发出。

**注意**:

- 颜色相关属性均为明暗主题成对出现, 自定义配色时建议 Light/Dark 两套同时设置, 否则切换主题后外观不一致。
- 按钮构造时固定高度为 38, 如需其他高度可再调用 `setFixedHeight` 覆盖。

### ElaIconButton

以 ElaAwesome 字体图标或 QPixmap 为内容的图标按钮, 常用于标题栏、工具区等只需要一个小图标的场合。继承自 QPushButton。

**头文件**: `#include "ElaIconButton.h"`

**基本用法**:

```cpp
#include <QHBoxLayout>
#include <QWidget>

#include "ElaIconButton.h"

void createIconButtons(QWidget* parent, QHBoxLayout* layout)
{
    // 图标 + 像素大小 + 固定宽高, 常见于标题栏按钮
    ElaIconButton* closeButton = new ElaIconButton(ElaIconType::Xmark, 17, 40, 30, parent);
    closeButton->setBorderRadius(4);
    QObject::connect(closeButton, &ElaIconButton::clicked, parent, [=]() {
        // 点击后的业务逻辑
    });

    // 仅指定图标与像素大小
    ElaIconButton* copyButton = new ElaIconButton(ElaIconType::Copy, 18, parent);

    // 运行时切换图标
    copyButton->setAwesome(ElaIconType::Download);

    // 使用图片作为按钮内容
    ElaIconButton* avatarButton = new ElaIconButton(QPixmap(":/Resource/Image/Cirno.jpg"), parent);
    avatarButton->setFixedSize(36, 36);

    layout->addWidget(closeButton);
    layout->addWidget(copyButton);
    layout->addWidget(avatarButton);
}
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `ElaIconButton(ElaIconType::IconName awesome, QWidget* parent = nullptr)` | 以图标构造, 图标像素大小默认 15 |
| `ElaIconButton(ElaIconType::IconName awesome, int pixelSize, QWidget* parent = nullptr)` | 以图标构造并指定图标像素大小 |
| `ElaIconButton(ElaIconType::IconName awesome, int pixelSize, int fixedWidth, int fixedHeight, QWidget* parent = nullptr)` | 以图标构造并同时固定按钮宽高 |
| `ElaIconButton(QPixmap pix, QWidget* parent = nullptr)` | 以图片构造 |
| `void setAwesome(ElaIconType::IconName awesome)` / `ElaIconType::IconName getAwesome() const` | 设置/获取当前 ElaAwesome 图标 |
| `void setPixmap(QPixmap pix)` | 切换为图片显示模式 |
| `void setBorderRadius(int BorderRadius)` | 圆角半径, 默认 0 |
| `void setOpacity(qreal Opacity)` | 整体不透明度, 默认 1 |
| `void setLightIconColor(QColor LightIconColor)` / `void setDarkIconColor(QColor DarkIconColor)` | 明暗主题下的图标颜色 |
| `void setLightHoverIconColor(QColor LightHoverIconColor)` / `void setDarkHoverIconColor(QColor DarkHoverIconColor)` | 明暗主题下悬停时的图标颜色 |
| `void setLightHoverColor(QColor LightHoverColor)` / `void setDarkHoverColor(QColor DarkHoverColor)` | 明暗主题下悬停时的背景色 |
| `void setIsSelected(bool IsSelected)` / `bool getIsSelected() const` | 选中态, 选中后保持悬停背景色 |

**信号**:

- `void clicked(bool checked = false)`: 继承自 QAbstractButton。

**注意**:

- 图标模式下按钮内容本质是 ElaAwesome 字体文本, 不要再调用 QPushButton::setText 传入普通文字。
- 未使用固定宽高的构造函数时, 按钮不会自动限制尺寸, 建议配合 `setFixedSize` 使用。

### ElaToolButton

FluentUI 风格的工具按钮, 支持图标与文本多种排列方式, 可挂载 ElaMenu 作为下拉菜单, 弹出时带指示器动画。继承自 QToolButton, 默认 popupMode 为 QToolButton::InstantPopup。

**头文件**: `#include "ElaToolButton.h"`

**基本用法**:

```cpp
#include <QHBoxLayout>
#include <QWidget>

#include "ElaMenu.h"
#include "ElaToolButton.h"

void createToolButtons(QWidget* parent, QHBoxLayout* layout)
{
    // 图标 + 文本 + 下拉菜单
    ElaToolButton* toolButton = new ElaToolButton(parent);
    toolButton->setIsTransparent(false); // 默认透明背景, 关闭后显示实体背景
    toolButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon); // QToolButton 原生接口
    toolButton->setText("Documentation");
    toolButton->setElaIcon(ElaIconType::FileDoc);
    ElaMenu* menu = new ElaMenu(parent);
    menu->addElaIconAction(ElaIconType::CardsBlank, "CardsBlank");
    menu->addElaIconAction(ElaIconType::EarthAmericas, "EarthAmericas");
    toolButton->setMenu(menu);

    // 纯图标工具按钮, 点击直接触发
    ElaToolButton* themeButton = new ElaToolButton(parent);
    themeButton->setFixedSize(35, 35);
    themeButton->setIsTransparent(false);
    themeButton->setElaIcon(ElaIconType::MoonStars);
    QObject::connect(themeButton, &ElaToolButton::clicked, parent, [=]() {
        // 点击后的业务逻辑, 例如切换主题
    });

    layout->addWidget(toolButton);
    layout->addWidget(themeButton);
}
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `explicit ElaToolButton(QWidget* parent = nullptr)` | 构造函数, 默认图标尺寸 22x22 |
| `void setBorderRadius(int BorderRadius)` / `int getBorderRadius() const` | 圆角半径 |
| `void setIsSelected(bool IsSelected)` / `bool getIsSelected() const` | 选中态, 选中后保持高亮背景 |
| `void setIsTransparent(bool isTransparent)` / `bool getIsTransparent() const` | 是否透明背景, 默认 true |
| `void setMenu(ElaMenu* menu)` | 挂载下拉菜单, 弹出/收起带指示器旋转动画 |
| `void setElaIcon(ElaIconType::IconName icon)` | 设置 ElaAwesome 图标 |
| `void setElaIcon(ElaIconType::IconName icon, int rotate)` | 设置图标并附加旋转角度 |

**信号**:

- `void clicked(bool checked = false)`: 继承自 QAbstractButton。
- `void triggered(QAction* action)`: 继承自 QToolButton, 菜单项触发时发出。

**注意**:

- 默认透明背景, 放在普通页面上时通常需要 `setIsTransparent(false)` 才能看到按钮轮廓。
- 图标与文本的排列由 QToolButton 原生接口 `setToolButtonStyle` 控制, 例如 Qt::ToolButtonTextUnderIcon、Qt::ToolButtonTextBesideIcon。
- `setMenu` 参数类型为 ElaMenu*, 传入普通 QMenu 无法获得对应样式与动画。

### ElaSplitButton

拆分按钮: 左侧主区域触发 clicked() 信号执行默认动作, 右侧箭头区域弹出 ElaMenu 提供更多选项, 适合"默认动作 + 备选动作"的场景, 例如发送/回复。继承自 QWidget。

**头文件**: `#include "ElaSplitButton.h"`

**基本用法**:

```cpp
#include <QHBoxLayout>
#include <QWidget>

#include "ElaMenu.h"
#include "ElaSplitButton.h"

void createSplitButton(QWidget* parent, QHBoxLayout* layout)
{
    ElaSplitButton* splitButton = new ElaSplitButton(parent);
    splitButton->setText("发送邮件");
    splitButton->setElaIcon(ElaIconType::Envelope);

    // 右侧箭头区域弹出的菜单
    ElaMenu* menu = new ElaMenu(parent);
    menu->addElaIconAction(ElaIconType::Reply, "回复");
    menu->addElaIconAction(ElaIconType::ReplyAll, "全部回复");
    menu->addElaIconAction(ElaIconType::Share, "转发");
    splitButton->setMenu(menu);

    // 左侧主区域点击触发默认动作
    QObject::connect(splitButton, &ElaSplitButton::clicked, parent, [=]() {
        // 执行默认动作, 例如直接发送
    });

    layout->addWidget(splitButton);
}
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `explicit ElaSplitButton(QWidget* parent = nullptr)` | 构造函数, 固定高度 35 |
| `void setText(QString Text)` / `QString getText() const` | 主区域显示的文本 |
| `void setElaIcon(ElaIconType::IconName ElaIcon)` / `ElaIconType::IconName getElaIcon() const` | 主区域图标, 默认 ElaIconType::None |
| `void setMenu(ElaMenu* menu)` / `ElaMenu* getMenu() const` | 右侧箭头区域弹出的菜单 |
| `void setBorderRadius(int BorderRadius)` / `int getBorderRadius() const` | 圆角半径, 默认 3 |

**信号**:

- `void clicked()`: 点击左侧主区域时发出; 点击右侧箭头区域只弹菜单, 不发出该信号。

**注意**:

- 未调用 `setMenu` 时, 点击右侧箭头区域没有任何动作, 应始终同时提供菜单。
- 菜单项的业务逻辑通过 `addElaIconAction` 返回的 QAction* 连接 `QAction::triggered` 实现。

### ElaDropDownButton

下拉按钮: 整个按钮点击后在下方弹出 ElaMenu, 自身不承载默认动作, 适合"排序方式"、"导出格式"这类纯选项入口。继承自 QWidget。

**头文件**: `#include "ElaDropDownButton.h"`

**基本用法**:

```cpp
#include <QAction>
#include <QHBoxLayout>
#include <QWidget>

#include "ElaDropDownButton.h"
#include "ElaMenu.h"

void createDropDownButton(QWidget* parent, QHBoxLayout* layout)
{
    ElaDropDownButton* dropDownButton = new ElaDropDownButton(parent);
    dropDownButton->setText("排序方式");
    dropDownButton->setElaIcon(ElaIconType::BarsSort);

    ElaMenu* menu = new ElaMenu(parent);
    QAction* byName = menu->addElaIconAction(ElaIconType::ArrowDownAZ, "按名称");
    menu->addElaIconAction(ElaIconType::Calendar, "按日期");
    menu->addElaIconAction(ElaIconType::ArrowDown19, "按大小");
    dropDownButton->setMenu(menu);

    // 业务逻辑挂在菜单项上
    QObject::connect(byName, &QAction::triggered, parent, [=]() {
        // 按名称排序
    });

    layout->addWidget(dropDownButton);
}
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `explicit ElaDropDownButton(QWidget* parent = nullptr)` | 构造函数, 固定高度 35 |
| `void setText(const QString& Text)` / `const QString& getText() const` | 按钮文本 |
| `void setElaIcon(ElaIconType::IconName ElaIcon)` / `ElaIconType::IconName getElaIcon() const` | 文本左侧图标, 默认 ElaIconType::None |
| `void setMenu(ElaMenu* menu)` / `ElaMenu* getMenu() const` | 点击后弹出的菜单 |
| `void setBorderRadius(int BorderRadius)` / `int getBorderRadius() const` | 圆角半径, 默认 6 |

**注意**:

- 组件本身没有 clicked 信号, 所有业务逻辑都应连接菜单中 QAction 的 `triggered` 信号。
- 如果需要"点击主体直接执行默认动作"的行为, 应改用 ElaSplitButton。

### ElaToggleButton

可切换选中状态的开关式按钮, 点击后在普通态与主题色高亮态之间切换并带渐变动画, 适合筛选开关、工具开关等二态场景。继承自 QWidget。

**头文件**: `#include "ElaToggleButton.h"`

**基本用法**:

```cpp
#include <QHBoxLayout>
#include <QWidget>

#include "ElaToggleButton.h"

void createToggleButton(QWidget* parent, QHBoxLayout* layout)
{
    ElaToggleButton* toggleButton = new ElaToggleButton("ToggleButton", parent);
    toggleButton->setFixedWidth(120);

    // 状态切换时发出 toggled 信号
    QObject::connect(toggleButton, &ElaToggleButton::toggled, parent, [=](bool checked) {
        // checked 为 true 表示当前处于选中态
    });

    // 代码设置初始状态
    toggleButton->setIsToggled(true);

    layout->addWidget(toggleButton);
}
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `explicit ElaToggleButton(QString text, QWidget* parent = nullptr)` | 以文本构造, 默认尺寸 80x32 |
| `void setText(QString Text)` / `QString getText() const` | 按钮文本 |
| `void setIsToggled(bool isToggled)` / `bool getIsToggled() const` | 设置/获取选中状态 |
| `void setBorderRadius(int BorderRadius)` / `int getBorderRadius() const` | 圆角半径, 默认 3 |

**信号**:

- `void toggled(bool checked)`: 选中状态变化时发出, 用户点击与代码调用 `setIsToggled` 都会触发。

**注意**:

- `setIsToggled` 也会发出 toggled 信号, 在信号槽内再调用 setIsToggled 时注意避免回环。

### ElaToggleSwitch

FluentUI 风格的拨动开关, 支持点击切换与拖拽滑块切换, 带滑动动画, 适合设置项中的开/关状态。继承自 QWidget, 固定尺寸 44x22。

**头文件**: `#include "ElaToggleSwitch.h"`

**基本用法**:

```cpp
#include <QHBoxLayout>
#include <QWidget>

#include "ElaToggleSwitch.h"

void createToggleSwitch(QWidget* parent, QHBoxLayout* layout, QWidget* targetWidget)
{
    ElaToggleSwitch* toggleSwitch = new ElaToggleSwitch(parent);

    // 常见用法: 用开关控制其他控件的启用状态
    QObject::connect(toggleSwitch, &ElaToggleSwitch::toggled, parent, [=](bool checked) {
        targetWidget->setDisabled(checked);
    });

    // 代码设置初始状态, 带滑动动画
    toggleSwitch->setIsToggled(true);

    layout->addWidget(toggleSwitch);
}
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `explicit ElaToggleSwitch(QWidget* parent = nullptr)` | 构造函数, 固定尺寸 44x22 |
| `void setIsToggled(bool isToggled)` / `bool getIsToggled() const` | 设置/获取开关状态, 设置时播放滑动动画 |

**信号**:

- `void toggled(bool checked)`: 开关状态变化时发出。

**注意**:

- 组件尺寸在构造时固定为 44x22, 不支持通过布局拉伸调整大小。
- 除点击外还支持按住滑块拖动到另一侧完成切换。

### ElaFloatButton

悬浮操作按钮 (FAB): 以圆形悬浮在父窗口四角之一, 父窗口尺寸变化时自动跟随重新定位, 可挂载 ElaMenu 在点击时弹出快捷菜单。继承自 QWidget。

**头文件**: `#include "ElaFloatButton.h"`

**基本用法**:

```cpp
#include <QWidget>

#include "ElaFloatButton.h"
#include "ElaMenu.h"

void createFloatButton(QWidget* parent)
{
    // 悬浮按钮直接以父窗口为锚, 不加入布局
    ElaFloatButton* floatButton = new ElaFloatButton(ElaIconType::Plus, parent);
    floatButton->setPosition(ElaFloatButton::BottomRight); // 悬浮在右下角
    floatButton->setMargin(30);                            // 距父窗口边缘 30

    // 点击弹出快捷菜单
    ElaMenu* menu = new ElaMenu(parent);
    menu->addElaIconAction(ElaIconType::Pen, "新建笔记");
    menu->addElaIconAction(ElaIconType::Upload, "上传文件");
    menu->addElaIconAction(ElaIconType::Share, "分享");
    floatButton->setMenu(menu);

    QObject::connect(floatButton, &ElaFloatButton::clicked, parent, [=]() {
        // 点击后的业务逻辑
    });
}
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `explicit ElaFloatButton(ElaIconType::IconName icon, QWidget* parent = nullptr)` | 以图标构造, 默认位置 BottomRight |
| `explicit ElaFloatButton(ElaIconType::IconName icon, Position position, QWidget* parent = nullptr)` | 以图标和位置构造 |
| `void setIcon(ElaIconType::IconName icon)` / `ElaIconType::IconName getIcon() const` | 设置/获取图标 |
| `void setPosition(Position position)` / `Position getPosition() const` | 悬浮位置: BottomRight, BottomLeft, TopRight, TopLeft |
| `void setButtonSize(int ButtonSize)` / `int getButtonSize() const` | 按钮直径, 默认 56 |
| `void setMargin(int Margin)` / `int getMargin() const` | 距父窗口边缘的间距, 默认 30 |
| `void setMenu(ElaMenu* menu)` / `ElaMenu* getMenu() const` | 点击时弹出的快捷菜单 |

**信号**:

- `void clicked()`: 点击按钮时发出; 设置了菜单时, 菜单弹出后同样会发出该信号。

**注意**:

- 必须传入 parent 才能自动定位: 组件通过监听父窗口的 Resize 事件保持在指定角落, 不要把它加入布局管理器。
- 位于底部 (BottomLeft/BottomRight) 时菜单向上弹出, 位于顶部时菜单向下弹出。
- 设置菜单后点击仍会发出 clicked 信号, 若只需要菜单入口, 不要再在 clicked 中绑定其他动作。

### ElaCopyButton

一键复制按钮: 点击后将预设文本写入系统剪贴板, 并在一段时间内切换为成功图标/文案作为反馈, 适合复制链接、命令、口令等场景。继承自 QPushButton。

**头文件**: `#include "ElaCopyButton.h"`

**基本用法**:

```cpp
#include <QHBoxLayout>
#include <QWidget>

#include "ElaCopyButton.h"

void createCopyButtons(QWidget* parent, QHBoxLayout* layout)
{
    // 纯图标模式, 默认 30x30
    ElaCopyButton* copyButton = new ElaCopyButton(parent);
    copyButton->setCopyText("https://github.com/RainbowCandyX/ElaWidgetTools");

    // 复制完成回调
    QObject::connect(copyButton, &ElaCopyButton::copyCompleted, parent, [=](const QString& text) {
        // text 为已写入剪贴板的内容
    });

    // 图标 + 文本模式, 并自定义成功反馈
    ElaCopyButton* textCopyButton = new ElaCopyButton(parent);
    textCopyButton->setCopyText("npm install ela-widget-tools");
    textCopyButton->setText("复制命令");         // 设置文本后自动切换为宽按钮
    textCopyButton->setSuccessText("已复制");    // 成功期间显示的文本
    textCopyButton->setSuccessDuration(2000);    // 成功状态保持 2000 毫秒

    layout->addWidget(copyButton);
    layout->addWidget(textCopyButton);
}
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `explicit ElaCopyButton(const QString& text, QWidget* parent = nullptr)` | 构造并预设待复制文本 |
| `void setCopyText(const QString& CopyText)` / `const QString& getCopyText() const` | 点击后写入剪贴板的文本 |
| `void setText(const QString& text)` | 按钮显示文本; 非空时自动切换为"图标 + 文本"宽按钮, 传空串恢复 30x30 纯图标 |
| `void setElaIcon(ElaIconType::IconName icon)` | 常态图标, 默认 ElaIconType::Copy |
| `void setSuccessIcon(ElaIconType::IconName icon)` | 复制成功期间显示的图标, 默认 ElaIconType::ClipboardCheck |
| `void setSuccessText(const QString& SuccessText)` / `const QString& getSuccessText() const` | 复制成功期间显示的文本 |
| `void setSuccessDuration(int SuccessDuration)` / `int getSuccessDuration() const` | 成功状态持续时长, 单位毫秒, 默认 1500 |
| `void setBorderRadius(int BorderRadius)` / `int getBorderRadius() const` | 圆角半径, 默认 3 |

**信号**:

- `void copyCompleted(const QString& text)`: 复制完成时发出, 参数为写入剪贴板的文本。

**注意**:

- 构造函数 `ElaCopyButton(const QString& text, ...)` 中的 text 是待复制内容, 不是按钮显示文本; 显示文本通过 `setText` 设置。
- 成功状态持续期间再次点击不会触发复制, 等待 SuccessDuration 结束恢复常态后才可再次复制。
- 待复制内容动态变化时 (例如跟随输入框), 应在内容变化处同步调用 `setCopyText`。

## 基础输入

### ElaLineEdit

Fluent 风格单行文本输入框, 继承自 QLineEdit。获得焦点时底部有主题色下划线展开动画, 内置 Fluent 风格右键菜单(撤销/恢复/剪切/复制/粘贴/删除/全选), 适用于表单、搜索框等所有单行输入场景。

**头文件**: `#include "ElaLineEdit.h"`

**基本用法**:

```cpp
#include "ElaLineEdit.h"

ElaLineEdit* lineEdit = new ElaLineEdit(this);
lineEdit->setPlaceholderText("请输入搜索关键字...");
// 圆角半径, 默认 6
lineEdit->setBorderRadius(6);
// 是否启用清除按钮(鼠标点击获得焦点时显示), 默认 true
lineEdit->setIsClearButtonEnable(true);

// 文本变化时实时响应
connect(lineEdit, &ElaLineEdit::textChanged, this, [=](const QString& text) {
    qDebug() << "当前文本:" << text;
});
// 失去焦点时获取最终输入
connect(lineEdit, &ElaLineEdit::focusOut, this, [=](QString text) {
    qDebug() << "输入完成:" << text;
});
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `void setBorderRadius(int borderRadius)` | 设置圆角半径, 默认 6 |
| `int getBorderRadius() const` | 获取圆角半径 |
| `void setIsClearButtonEnable(bool isClearButtonEnable)` | 设置是否启用清除按钮, 默认 true |
| `bool getIsClearButtonEnable() const` | 获取清除按钮是否启用 |
| `void setPlaceholderText(const QString& text)` | 设置占位提示文本(继承自 QLineEdit) |
| `QString text() const` | 获取当前文本(继承自 QLineEdit) |
| `void setText(const QString& text)` | 设置文本(继承自 QLineEdit) |
| `void setReadOnly(bool readOnly)` | 设置只读, 只读时右键菜单自动隐藏编辑项(继承自 QLineEdit) |
| `void setMaxLength(int length)` | 设置最大输入长度(继承自 QLineEdit) |

**信号**:

| 信号 | 说明 |
| --- | --- |
| `void focusIn(QString text)` | 获得焦点时发出, 携带当前文本 |
| `void focusOut(QString text)` | 失去焦点时发出, 携带当前文本 |
| `void wmFocusOut(QString text)` | 失去焦点(非弹出菜单原因)时发出, 与窗口点击事件总线联动 |
| `void textChanged(const QString& text)` | 文本变化时发出(继承自 QLineEdit) |
| `void returnPressed()` | 按下回车时发出(继承自 QLineEdit) |

**注意**:

- 构造函数中调用了 setFixedHeight(35), 高度固定为 35, 需要其他高度时再次调用 setFixedHeight 覆盖。
- 清除按钮仅在鼠标点击获得焦点(Qt::MouseFocusReason)时显示, 失去焦点后自动隐藏; 通过 Tab 键获得焦点时不显示。
- 底部下划线动画仅在鼠标点击获得焦点(Qt::MouseFocusReason)时触发。

### ElaPasswordBox

Fluent 风格密码输入框, 继承自 QLineEdit。默认以密文(QLineEdit::Password)显示, 输入框右侧内置眼睛图标按钮, 点击可切换明文/密文显示, 适用于登录、注册等密码输入场景。

**头文件**: `#include "ElaPasswordBox.h"`

**基本用法**:

```cpp
#include "ElaPasswordBox.h"

ElaPasswordBox* passwordBox = new ElaPasswordBox(this);
passwordBox->setFixedSize(280, 38);
passwordBox->setPlaceholderText("请输入密码...");

// 代码控制明文显示(等价于点击眼睛按钮)
passwordBox->setIsPasswordVisible(true);

// 失去焦点时校验密码
connect(passwordBox, &ElaPasswordBox::focusOut, this, [=](QString text) {
    qDebug() << "密码长度:" << text.length();
});
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `void setBorderRadius(int borderRadius)` | 设置圆角半径, 默认 6 |
| `int getBorderRadius() const` | 获取圆角半径 |
| `void setIsPasswordVisible(bool isPasswordVisible)` | 设置密码是否明文显示, 默认 false; 同时切换眼睛图标状态 |
| `bool getIsPasswordVisible() const` | 获取密码是否明文显示 |
| `void setPlaceholderText(const QString& text)` | 设置占位提示文本(继承自 QLineEdit) |
| `QString text() const` | 获取当前输入的密码(继承自 QLineEdit) |
| `void setMaxLength(int length)` | 设置最大输入长度(继承自 QLineEdit) |

**信号**:

| 信号 | 说明 |
| --- | --- |
| `void focusIn(QString text)` | 获得焦点时发出, 携带当前文本 |
| `void focusOut(QString text)` | 失去焦点时发出, 携带当前文本 |
| `void wmFocusOut(QString text)` | 失去焦点(非弹出菜单原因)时发出 |
| `void pIsPasswordVisibleChanged()` | 明文/密文状态切换时发出 |

**注意**:

- 出于密码保护考虑, 右键菜单不提供剪切和复制项, 仅有撤销/恢复/粘贴/删除/全选。
- 构造函数中调用了 setFixedHeight(35); 样式表在右侧预留了 36px 内边距用于放置眼睛按钮, 自定义样式表时需保留该内边距, 否则文本会与图标重叠。

### ElaPlainTextEdit

Fluent 风格多行纯文本编辑框, 继承自 QPlainTextEdit。内置 ElaScrollBar 平滑滚动条、主题化右键菜单和聚焦下划线动画, 适用于日志展示、备注、多行文本录入等场景。

**头文件**: `#include "ElaPlainTextEdit.h"`

**基本用法**:

```cpp
#include "ElaPlainTextEdit.h"

// 构造时直接传入初始文本
ElaPlainTextEdit* edit = new ElaPlainTextEdit("初始内容", this);
edit->setPlaceholderText("请输入备注...");

// 追加一行文本
edit->appendPlainText("追加的一行");

// 文本变化时响应
connect(edit, &ElaPlainTextEdit::textChanged, this, [=]() {
    qDebug() << "当前内容:" << edit->toPlainText();
});
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `explicit ElaPlainTextEdit(QWidget* parent = nullptr)` | 构造空编辑框 |
| `explicit ElaPlainTextEdit(const QString& text, QWidget* parent = nullptr)` | 构造并设置初始文本 |
| `void setPlainText(const QString& text)` | 设置全部文本(继承自 QPlainTextEdit) |
| `QString toPlainText() const` | 获取全部文本(继承自 QPlainTextEdit) |
| `void appendPlainText(const QString& text)` | 在末尾追加一段文本(继承自 QPlainTextEdit) |
| `void setPlaceholderText(const QString& placeholderText)` | 设置占位提示文本(继承自 QPlainTextEdit) |
| `void setReadOnly(bool ro)` | 设置只读, 只读时右键菜单自动隐藏编辑项(继承自 QPlainTextEdit) |
| `void clear()` | 清空内容(继承自 QPlainTextEdit) |

**信号**:

| 信号 | 说明 |
| --- | --- |
| `void textChanged()` | 文本变化时发出(继承自 QPlainTextEdit) |

**注意**:

- 仅支持纯文本, 不支持富文本; 库中没有对应的富文本编辑组件。
- 水平和垂直滚动条在构造时已替换为 ElaScrollBar, 无需手动设置。

### ElaSpinBox

Fluent 风格整数微调框, 继承自 QSpinBox。在 QSpinBox 基础上提供四种加减按钮布局模式(ButtonMode), 并内置主题化右键菜单(含增加/减少菜单项)。

**头文件**: `#include "ElaSpinBox.h"`

**基本用法**:

```cpp
#include "ElaSpinBox.h"

ElaSpinBox* spinBox = new ElaSpinBox(this);
// 取值范围与步长(继承自 QSpinBox)
spinBox->setRange(0, 100);
spinBox->setSingleStep(5);
spinBox->setValue(50);

// 切换加减按钮布局: Inline / Compact / Side / PMSide
spinBox->setButtonMode(ElaSpinBoxType::Compact);

connect(spinBox, QOverload<int>::of(&ElaSpinBox::valueChanged), this, [=](int value) {
    qDebug() << "当前值:" << value;
});
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `void setButtonMode(ElaSpinBoxType::ButtonMode buttonMode)` | 设置加减按钮布局模式, 可选 Inline(默认)/Compact/Side/PMSide |
| `ElaSpinBoxType::ButtonMode getButtonMode() const` | 获取当前按钮布局模式 |
| `void setRange(int minimum, int maximum)` | 设置取值范围(继承自 QSpinBox) |
| `void setValue(int val)` | 设置当前值(继承自 QSpinBox) |
| `int value() const` | 获取当前值(继承自 QSpinBox) |
| `void setSingleStep(int val)` | 设置单步步长(继承自 QSpinBox) |
| `void setPrefix(const QString& prefix)` | 设置数值前缀(继承自 QSpinBox) |
| `void setSuffix(const QString& suffix)` | 设置数值后缀(继承自 QSpinBox) |

**信号**:

| 信号 | 说明 |
| --- | --- |
| `void valueChanged(int value)` | 数值变化时发出(继承自 QSpinBox) |
| `void pButtonModeChanged()` | 按钮布局模式变化时发出 |

**注意**:

- ButtonMode 枚举定义在 ElaDef.h 的 ElaSpinBoxType 中: Inline(按钮内嵌右侧)、Compact(紧凑)、Side(两侧)、PMSide(加减号分居两侧)。
- 构造时固定尺寸为 115x35; 调用 setButtonMode 时最小宽度会被提升到 90。
- Inline 模式下文本左对齐, 其余模式下文本居中对齐。

### ElaDoubleSpinBox

Fluent 风格浮点数微调框, 继承自 QDoubleSpinBox。与 ElaSpinBox 一致, 支持四种加减按钮布局模式, 适用于需要小数精度的数值输入场景。

**头文件**: `#include "ElaDoubleSpinBox.h"`

**基本用法**:

```cpp
#include "ElaDoubleSpinBox.h"

ElaDoubleSpinBox* doubleSpinBox = new ElaDoubleSpinBox(this);
// 范围、小数位数与步长(继承自 QDoubleSpinBox)
doubleSpinBox->setRange(0.0, 10.0);
doubleSpinBox->setDecimals(2);
doubleSpinBox->setSingleStep(0.1);
doubleSpinBox->setValue(3.14);

// 切换加减按钮布局
doubleSpinBox->setButtonMode(ElaSpinBoxType::Side);

connect(doubleSpinBox, QOverload<double>::of(&ElaDoubleSpinBox::valueChanged), this, [=](double value) {
    qDebug() << "当前值:" << value;
});
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `void setButtonMode(ElaSpinBoxType::ButtonMode buttonMode)` | 设置加减按钮布局模式, 可选 Inline(默认)/Compact/Side/PMSide |
| `ElaSpinBoxType::ButtonMode getButtonMode() const` | 获取当前按钮布局模式 |
| `void setRange(double minimum, double maximum)` | 设置取值范围(继承自 QDoubleSpinBox) |
| `void setValue(double val)` | 设置当前值(继承自 QDoubleSpinBox) |
| `double value() const` | 获取当前值(继承自 QDoubleSpinBox) |
| `void setDecimals(int prec)` | 设置小数位数(继承自 QDoubleSpinBox) |
| `void setSingleStep(double val)` | 设置单步步长(继承自 QDoubleSpinBox) |
| `void setSuffix(const QString& suffix)` | 设置数值后缀(继承自 QDoubleSpinBox) |

**信号**:

| 信号 | 说明 |
| --- | --- |
| `void valueChanged(double value)` | 数值变化时发出(继承自 QDoubleSpinBox) |
| `void pButtonModeChanged()` | 按钮布局模式变化时发出 |

**注意**:

- ButtonMode 与 ElaSpinBox 共用 ElaSpinBoxType::ButtonMode 枚举。
- ElaInputDialog 内部使用该组件作为浮点数输入控件。

### ElaNumberBox

自绘数字输入框, 继承自 QWidget(不基于 QSpinBox)。左右两端为减/加按钮, 中间显示数值; 双击数值区域进入行内编辑, 支持鼠标滚轮和上下方向键调节, 整数与小数通过 Decimals 属性统一支持。

**头文件**: `#include "ElaNumberBox.h"`

**基本用法**:

```cpp
#include "ElaNumberBox.h"

// 整数用法
ElaNumberBox* numberBox = new ElaNumberBox(this);
numberBox->setMinimum(-50);
numberBox->setMaximum(200);
numberBox->setStep(5);
numberBox->setValue(25);

// 小数用法: 设置小数位数与步长
ElaNumberBox* decimalBox = new ElaNumberBox(this);
decimalBox->setMinimum(0);
decimalBox->setMaximum(10);
decimalBox->setStep(0.1);
decimalBox->setDecimals(2);
decimalBox->setValue(3.14);

// 越界循环: 超过最大值回到最小值, 反之亦然
numberBox->setIsWrapping(true);

connect(numberBox, &ElaNumberBox::valueChanged, this, [=](double value) {
    qDebug() << "当前值:" << value;
});
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `void setValue(double value)` | 设置当前值, 自动钳制到 [Minimum, Maximum] 范围 |
| `double getValue() const` | 获取当前值 |
| `void setMinimum(double minimum)` | 设置最小值, 默认 0 |
| `void setMaximum(double maximum)` | 设置最大值, 默认 100 |
| `void setStep(double step)` | 设置单步步长, 默认 1 |
| `void setDecimals(int decimals)` | 设置显示小数位数, 默认 0(整数显示) |
| `void setIsWrapping(bool isWrapping)` | 设置越界是否循环, 默认 false |
| `bool getIsWrapping() const` | 获取越界是否循环 |
| `void setBorderRadius(int borderRadius)` | 设置圆角半径, 默认 6 |
| `void stepUp()` | 数值增加一个步长 |
| `void stepDown()` | 数值减少一个步长 |

**信号**:

| 信号 | 说明 |
| --- | --- |
| `void valueChanged(double value)` | 数值变化时发出, 参数为钳制后的新值 |

**注意**:

- 构造时固定尺寸为 160x36, 需要其他尺寸时调用 setFixedSize 覆盖。
- 交互方式: 点击左右按钮步进; 双击中间数值区域进入编辑, Enter/失焦确认, Esc 取消; 焦点在控件上时可用上下方向键调节, 鼠标悬停在控件上时可用滚轮调节(滚轮不要求焦点)。
- 数值统一以 double 存储, 整数场景保持 Decimals 为 0 即可。
- IsWrapping 为 false 时, 数值到达边界后对应按钮的图标显示为禁用色。

### ElaSlider

Fluent 风格滑动条, 继承自 QSlider。仅替换绘制样式(圆形滑块与主题色轨道), 接口与 QSlider 完全一致, 默认水平方向。

**头文件**: `#include "ElaSlider.h"`

**基本用法**:

```cpp
#include "ElaSlider.h"

// 默认水平方向
ElaSlider* slider = new ElaSlider(this);
slider->setRange(0, 100);
slider->setValue(50);

// 构造垂直方向滑动条
ElaSlider* vSlider = new ElaSlider(Qt::Vertical, this);

connect(slider, &ElaSlider::valueChanged, this, [=](int value) {
    qDebug() << "当前值:" << value;
});
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `explicit ElaSlider(QWidget* parent = nullptr)` | 构造水平方向滑动条 |
| `explicit ElaSlider(Qt::Orientation orientation, QWidget* parent = nullptr)` | 构造指定方向滑动条 |
| `void setRange(int min, int max)` | 设置取值范围(继承自 QAbstractSlider) |
| `void setValue(int value)` | 设置当前值(继承自 QAbstractSlider) |
| `int value() const` | 获取当前值(继承自 QAbstractSlider) |
| `void setOrientation(Qt::Orientation orientation)` | 设置方向(继承自 QSlider) |
| `void setSingleStep(int step)` | 设置方向键单步步长(继承自 QAbstractSlider) |
| `void setPageStep(int step)` | 设置 PageUp/PageDown 步长(继承自 QAbstractSlider) |

**信号**:

| 信号 | 说明 |
| --- | --- |
| `void valueChanged(int value)` | 数值变化时发出(继承自 QAbstractSlider) |
| `void sliderMoved(int position)` | 拖动滑块时发出(继承自 QAbstractSlider) |
| `void sliderReleased()` | 释放滑块时发出(继承自 QAbstractSlider) |

### ElaCheckBox

Fluent 风格复选框, 继承自 QCheckBox。替换指示器绘制样式并统一字体, 接口与 QCheckBox 一致, 适用于多选、开关型选项等场景。

**头文件**: `#include "ElaCheckBox.h"`

**基本用法**:

```cpp
#include "ElaCheckBox.h"

// 构造时直接传入文本
ElaCheckBox* checkBox = new ElaCheckBox("启用自动更新", this);
checkBox->setChecked(true);

// 指示器圆角, 默认 3
checkBox->setBorderRadius(3);

connect(checkBox, &ElaCheckBox::toggled, this, [=](bool checked) {
    qDebug() << "勾选状态:" << checked;
});
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `explicit ElaCheckBox(const QString& text, QWidget* parent = nullptr)` | 构造并设置文本 |
| `void setBorderRadius(int borderRadius)` | 设置勾选指示器圆角半径, 默认 3 |
| `int getBorderRadius() const` | 获取指示器圆角半径 |
| `void setText(const QString& text)` | 设置文本(继承自 QAbstractButton) |
| `void setChecked(bool checked)` | 设置勾选状态(继承自 QAbstractButton) |
| `bool isChecked() const` | 获取勾选状态(继承自 QAbstractButton) |
| `void setTristate(bool y = true)` | 启用三态模式(继承自 QCheckBox) |

**信号**:

| 信号 | 说明 |
| --- | --- |
| `void toggled(bool checked)` | 勾选状态切换时发出(继承自 QAbstractButton) |

**注意**:

- 构造时字体像素大小固定为 15, 需要其他字号时通过 setFont 覆盖。

### ElaRadioButton

Fluent 风格单选按钮, 继承自 QRadioButton。替换指示器绘制样式并跟随主题切换, 接口与 QRadioButton 一致, 适用于互斥的单选项场景。

**头文件**: `#include "ElaRadioButton.h"`

**基本用法**:

```cpp
#include "ElaRadioButton.h"
#include <QButtonGroup>

ElaRadioButton* inlineButton = new ElaRadioButton("Inline", this);
ElaRadioButton* compactButton = new ElaRadioButton("Compact", this);
inlineButton->setChecked(true);

// 用 QButtonGroup 显式分组并携带 id
QButtonGroup* buttonGroup = new QButtonGroup(this);
buttonGroup->addButton(inlineButton, 0);
buttonGroup->addButton(compactButton, 1);
connect(buttonGroup, QOverload<QAbstractButton*, bool>::of(&QButtonGroup::buttonToggled),
        this, [=](QAbstractButton* button, bool isToggled) {
    if (isToggled)
    {
        qDebug() << "选中项 id:" << buttonGroup->id(button);
    }
});
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `explicit ElaRadioButton(QWidget* parent = nullptr)` | 构造空单选按钮 |
| `explicit ElaRadioButton(const QString& text, QWidget* parent = nullptr)` | 构造并设置文本 |
| `void setText(const QString& text)` | 设置文本(继承自 QAbstractButton) |
| `void setChecked(bool checked)` | 设置选中状态(继承自 QAbstractButton) |
| `bool isChecked() const` | 获取选中状态(继承自 QAbstractButton) |

**信号**:

| 信号 | 说明 |
| --- | --- |
| `void toggled(bool checked)` | 选中状态切换时发出(继承自 QAbstractButton) |

**注意**:

- 同一父容器内的多个单选按钮自动互斥; 跨容器分组或需要 id 时使用 QButtonGroup 显式管理。
- 构造时固定高度 20, 字体像素大小固定为 15, 需要调整时分别通过 setFixedHeight 和 setFont 覆盖。

## 高级输入

### ElaComboBox

Fluent 风格下拉框, 继承自 QComboBox, 完整兼容 QComboBox 的全部接口, 在其基础上提供圆角边框、展开动画与主题跟随的弹出列表。适用于所有单选下拉场景。

**头文件**: `#include "ElaComboBox.h"`

**基本用法**:

```cpp
#include "ElaComboBox.h"

// 创建下拉框并填充选项
ElaComboBox* comboBox = new ElaComboBox(this);
comboBox->addItems({"选项一", "选项二", "选项三"});
comboBox->setCurrentIndex(1);

// 调整圆角半径, 默认值为 3
comboBox->setBorderRadius(6);

// 开启可编辑模式, 内部会同步替换 lineEdit 的样式
comboBox->setEditable(true);

// 监听选中项变化(继承自 QComboBox 的信号)
connect(comboBox, &ElaComboBox::currentIndexChanged, this, [=](int index) {
    qDebug() << "当前选中索引:" << index;
});
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `void setBorderRadius(int borderRadius)` | 设置圆角半径, 默认 3 |
| `int getBorderRadius() const` | 获取圆角半径 |
| `void setEditable(bool editable)` | 设置是否可编辑, 并同步应用 Ela 样式到内部 lineEdit |
| `void addItem(const QString& text)` | 添加单个选项(继承自 QComboBox) |
| `void addItems(const QStringList& texts)` | 批量添加选项(继承自 QComboBox) |
| `void setCurrentIndex(int index)` | 设置当前选中索引(继承自 QComboBox) |
| `QString currentText() const` | 获取当前选中文本(继承自 QComboBox) |

**信号**:

- `currentIndexChanged(int index)`: 选中索引变化(继承自 QComboBox)
- `currentTextChanged(const QString& text)`: 选中文本变化(继承自 QComboBox)

**注意**:

- `setEditable(bool)` 是对 QComboBox 非虚函数的同名遮蔽, 必须通过 `ElaComboBox*` 指针调用才能生效 Ela 样式; 通过 `QComboBox*` 基类指针调用会绕过样式处理。

### ElaMultiSelectComboBox

多选下拉框, 继承自 QComboBox。弹出列表中可勾选多个选项, 框体内以文本列表形式显示当前选中项, 适用于标签筛选、多条件过滤等场景。

**头文件**: `#include "ElaMultiSelectComboBox.h"`

**基本用法**:

```cpp
#include "ElaMultiSelectComboBox.h"

ElaMultiSelectComboBox* multiComboBox = new ElaMultiSelectComboBox(this);
multiComboBox->addItems({"苹果", "香蕉", "橙子", "西瓜", "葡萄"});

// 按文本列表预设选中项
multiComboBox->setCurrentSelection(QStringList{"苹果", "橙子"});

// 在弹出列表中显示复选框, 默认为 false
multiComboBox->setShowCheckBox(true);

// 监听选中文本列表变化
connect(multiComboBox, &ElaMultiSelectComboBox::currentTextListChanged, this,
        [=](QStringList selectedTextList) {
    qDebug() << "当前选中:" << selectedTextList;
});
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `void setCurrentSelection(QString selection)` | 按文本设置单个选中项 |
| `void setCurrentSelection(QStringList selection)` | 按文本列表设置多个选中项 |
| `void setCurrentSelection(int index)` | 按索引设置单个选中项 |
| `void setCurrentSelection(QList<int> selectionIndex)` | 按索引列表设置多个选中项 |
| `QStringList getCurrentSelection() const` | 获取当前选中项的文本列表 |
| `QList<int> getCurrentSelectionIndex() const` | 获取当前选中项的索引列表 |
| `void setShowCheckBox(bool showCheckBox)` | 设置弹出列表是否显示复选框, 默认 false |
| `void setBorderRadius(int borderRadius)` | 设置圆角半径, 默认 3 |

**信号**:

- `itemSelectionChanged(QVector<bool> itemSelection)`: 每个选项的选中状态数组变化
- `currentTextListChanged(QStringList selectedTextList)`: 选中文本列表变化

**注意**:

- 选项数据仍通过继承的 `QComboBox::addItems` 填充, 但取值必须使用 `getCurrentSelection()` 系列接口, 不要使用 `currentText()`。

### ElaAutoComplete

自动补全输入框, 继承自 QWidget, 内部组合了 ElaLineEdit 与弹出候选列表。输入时按指定匹配模式实时过滤候选词, 适用于城市选择、搜索输入等场景。

**头文件**: `#include "ElaAutoComplete.h"`

**基本用法**:

```cpp
#include "ElaAutoComplete.h"

ElaAutoComplete* autoComplete = new ElaAutoComplete(this);
autoComplete->setPlaceholderText("输入城市名称...");

// 设置候选词列表
autoComplete->setCompletions({"北京", "上海", "广州", "深圳", "杭州", "成都"});

// 设置匹配模式: Contains / StartsWith / EndsWith / RegExp
autoComplete->setMatchMode(ElaAutoComplete::StartsWith);

// 设置大小写敏感性, 默认 Qt::CaseInsensitive
autoComplete->setCaseSensitivity(Qt::CaseInsensitive);

// 候选项被选中时触发
connect(autoComplete, &ElaAutoComplete::completionSelected, this, [=](const QString& text) {
    qDebug() << "已选择:" << text;
});
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `void setCompletions(const QStringList& completions)` | 设置候选词列表 |
| `QStringList completions() const` | 获取候选词列表 |
| `void setMatchMode(MatchMode mode)` | 设置匹配模式, 枚举值: `Contains`、`StartsWith`、`EndsWith`、`RegExp` |
| `MatchMode matchMode() const` | 获取匹配模式 |
| `void setText(const QString& text)` | 设置输入框文本 |
| `QString text() const` | 获取输入框文本 |
| `void setPlaceholderText(const QString& placeholderText)` | 设置占位提示文本 |
| `void setCaseSensitivity(Qt::CaseSensitivity caseSensitivity)` | 设置匹配大小写敏感性, 默认 Qt::CaseInsensitive |
| `void setMaxVisibleItems(int maxVisibleItems)` | 设置弹出列表最大可见条数, 默认 6 |
| `void setBorderRadius(int borderRadius)` | 设置圆角半径, 默认 6 |
| `void setFixedHeight(int h)` | 设置固定高度, 同步调整内部输入框 |

**信号**:

- `textChanged(const QString& text)`: 文本变化(含代码设置)
- `textEdited(const QString& text)`: 用户编辑文本
- `completionSelected(const QString& completion)`: 用户从候选列表选中某项
- `returnPressed(const QString& text)`: 输入框按下回车

**注意**:

- `RegExp` 模式下输入内容将作为正则表达式解析, 用户输入非法正则时无匹配结果, 属正常表现。

### ElaSuggestBox

搜索建议框, 继承自 QWidget。输入关键字实时弹出建议列表, 每条建议可携带图标与自定义 QVariantMap 数据, 典型用途是应用内全局搜索与页面导航跳转。

**头文件**: `#include "ElaSuggestBox.h"`

**基本用法**:

```cpp
#include "ElaSuggestBox.h"

ElaSuggestBox* suggestBox = new ElaSuggestBox(this);
suggestBox->setFixedHeight(32);
suggestBox->setPlaceholderText("搜索关键字");

// 添加建议项, 可携带图标与自定义数据, 返回该建议项的唯一 key
QVariantMap data;
data.insert("ElaPageKey", "HomePage");
QString suggestKey = suggestBox->addSuggestion(ElaIconType::House, "主页", data);

// 点击建议项时取出携带的数据执行跳转
connect(suggestBox, &ElaSuggestBox::suggestionClicked, this,
        [=](const ElaSuggestBox::SuggestData& suggestData) {
    QString pageKey = suggestData.getSuggestData().value("ElaPageKey").toString();
    qDebug() << "跳转页面:" << pageKey;
});

// 按 key 移除建议项
suggestBox->removeSuggestion(suggestKey);
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `QString addSuggestion(const QString& suggestText, const QVariantMap& suggestData = {})` | 添加纯文本建议项, 返回唯一 key |
| `QString addSuggestion(ElaIconType::IconName icon, const QString& suggestText, const QVariantMap& suggestData = {})` | 添加带图标的建议项 |
| `QStringList addSuggestion(const QList<ElaSuggestBox::SuggestData>& suggestDataList)` | 批量添加建议项, 返回 key 列表 |
| `void removeSuggestion(const QString& suggestKey)` | 按 key 移除建议项 |
| `void removeSuggestion(int index)` | 按索引移除建议项 |
| `void clearSuggestion()` | 清空全部建议项 |
| `void setPlaceholderText(const QString& placeholderText)` | 设置占位提示文本 |
| `void setCaseSensitivity(Qt::CaseSensitivity caseSensitivity)` | 设置匹配大小写敏感性, 默认 Qt::CaseInsensitive |
| `void setBorderRadius(int borderRadius)` | 设置圆角半径, 默认 6 |

**信号**:

- `suggestionClicked(const ElaSuggestBox::SuggestData& suggestData)`: 建议项被点击

**注意**:

- `SuggestData` 结构体通过 `getElaIcon()`、`getSuggestText()`、`getSuggestKey()`、`getSuggestData()` 读取各字段。
- 建议项携带的 `QVariantMap` 是业务数据通道, ElaWidgetToolsExample 中即通过其中的 `ElaPageKey` 实现搜索结果到导航页面的跳转。

### ElaTreeSelect

树形下拉选择框, 继承自 QWidget。点击后弹出基于 QStandardItemModel 的树形列表, 支持展开折叠与内置搜索, 适用于地区选择、分类选择等层级数据场景。

**头文件**: `#include "ElaTreeSelect.h"`

**基本用法**:

```cpp
#include "ElaTreeSelect.h"
#include <QStandardItemModel>

ElaTreeSelect* treeSelect = new ElaTreeSelect(this);
treeSelect->setPlaceholderText("请选择地区...");
treeSelect->setMinimumWidth(280);

// 构建层级数据模型
QStandardItemModel* model = new QStandardItemModel(this);
QStandardItem* beijing = new QStandardItem("北京");
beijing->appendRow(new QStandardItem("朝阳区"));
beijing->appendRow(new QStandardItem("海淀区"));
model->appendRow(beijing);
QStandardItem* shanghai = new QStandardItem("上海");
shanghai->appendRow(new QStandardItem("浦东新区"));
model->appendRow(shanghai);
treeSelect->setModel(model);

// 监听选中文本变化
connect(treeSelect, &ElaTreeSelect::currentTextChanged, this, [=](const QString& text) {
    qDebug() << "已选择:" << text;
});
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `void setModel(QStandardItemModel* model)` | 设置树形数据模型 |
| `QStandardItemModel* model() const` | 获取数据模型 |
| `void setCurrentIndex(const QModelIndex& index)` | 设置当前选中节点 |
| `QModelIndex currentIndex() const` | 获取当前选中节点索引 |
| `QString currentText() const` | 获取当前选中节点文本 |
| `void expandAll()` | 展开全部节点 |
| `void collapseAll()` | 折叠全部节点 |
| `void setPlaceholderText(const QString& placeholderText)` | 设置占位提示文本 |
| `void setIsSearchVisible(bool isSearchVisible)` | 设置弹出面板是否显示搜索框, 默认 true |
| `void setItemHeight(int itemHeight)` | 设置节点行高, 默认 35 |
| `void setMaxVisibleItems(int maxVisibleItems)` | 设置弹出列表最大可见行数, 默认 8 |
| `void setIsEditable(bool isEditable)` | 设置框体文本是否可编辑, 默认 false |

**信号**:

- `currentIndexChanged(const QModelIndex& index)`: 选中节点变化
- `currentTextChanged(const QString& text)`: 选中文本变化

**注意**:

- 组件默认固定高度 35、最小宽度 180, 数据模型的所有权不会转移, 由调用方管理其生命周期。

### ElaKeyBinder

按键绑定控件, 继承自 QLabel。点击后弹出 ElaContentDialog 捕获用户按键, 记录按键文本与平台原生虚拟键码, 适用于快捷键设置界面。

**头文件**: `#include "ElaKeyBinder.h"`

**基本用法**:

```cpp
#include "ElaKeyBinder.h"

// 创建按键绑定控件, 点击后弹出捕获对话框
// 对话框提供 取消 / 重置 / 确认 三个按钮
ElaKeyBinder* keyBinder = new ElaKeyBinder(this);

// 预设默认绑定的按键文本
keyBinder->setBinderKeyText("F5");

// 绑定结果变化时触发
connect(keyBinder, &ElaKeyBinder::binderKeyTextChanged, this, [=](QString binderKeyText) {
    qDebug() << "绑定按键:" << binderKeyText;
});
connect(keyBinder, &ElaKeyBinder::nativeVirtualBinderKeyChanged, this, [=](quint32 binderKey) {
    qDebug() << "原生虚拟键码:" << binderKey;
});
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `void setBinderKeyText(QString binderKeyText)` | 设置绑定按键的显示文本 |
| `QString getBinderKeyText() const` | 获取绑定按键的显示文本 |
| `void setNativeVirtualBinderKey(quint32 binderKey)` | 设置绑定按键的原生虚拟键码 |
| `quint32 getNativeVirtualBinderKey() const` | 获取绑定按键的原生虚拟键码 |
| `void setBorderRadius(int borderRadius)` | 设置圆角半径, 默认 5 |

**信号**:

- `binderKeyTextChanged(QString binderKeyText)`: 绑定按键文本变化
- `nativeVirtualBinderKeyChanged(quint32 binderKey)`: 原生虚拟键码变化

**注意**:

- 原生虚拟键码取自操作系统, 同一物理按键在 Windows 与 macOS 上的键码不同, 跨平台持久化配置时建议以 `getBinderKeyText()` 的文本为准。
- 捕获对话框以 `window()` 为父窗口, 控件必须置于顶层窗口的控件树内再交互。

### ElaCaptcha

验证码输入框, 继承自 QWidget。由一组分段输入格子组成, 支持逐位输入与自动跳格, 输满后发出完成信号, 适用于短信验证码、PIN 码输入场景。

**头文件**: `#include "ElaCaptcha.h"`

**基本用法**:

```cpp
#include "ElaCaptcha.h"

ElaCaptcha* captcha = new ElaCaptcha(this);

// 仅允许输入数字, 枚举值: DigitOnly / AlphaNumeric, 默认 AlphaNumeric
captcha->setInputMode(ElaCaptcha::DigitOnly);

// 设置验证码位数, 默认 6
captcha->setCodeLength(4);

// 输满全部位数时触发
connect(captcha, &ElaCaptcha::codeCompleted, this, [=](const QString& code) {
    qDebug() << "输入完成:" << code;
});

// 清空全部输入并将焦点移回第一格
captcha->clear();
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `void setInputMode(InputMode mode)` | 设置输入模式, 枚举值: `DigitOnly`(仅数字)、`AlphaNumeric`(数字加字母), 默认 AlphaNumeric |
| `InputMode getInputMode() const` | 获取输入模式 |
| `QString getCode() const` | 获取当前已输入的完整内容 |
| `void clear()` | 清空全部输入并聚焦第一格 |
| `void setCodeLength(int codeLength)` | 设置验证码位数, 默认 6 |
| `void setBoxSize(int boxSize)` | 设置单个输入格边长, 默认 42 |
| `void setBoxSpacing(int boxSpacing)` | 设置输入格间距, 默认 8 |
| `void setBorderRadius(int borderRadius)` | 设置输入格圆角半径, 默认 6 |

**信号**:

- `codeCompleted(const QString& code)`: 全部位数输入完成
- `codeChanged(const QString& code)`: 输入内容变化

**注意**:

- 该组件是验证码输入控件, 不负责生成验证码图片; 校验逻辑由业务侧在 `codeCompleted` 信号中实现。

### ElaRatingControl

星级评分控件, 继承自 QWidget。鼠标悬停实时预览、点击确定评分, 支持只读展示模式, 适用于评价、打分场景。

**头文件**: `#include "ElaRatingControl.h"`

**基本用法**:

```cpp
#include "ElaRatingControl.h"

ElaRatingControl* rating = new ElaRatingControl(this);

// 设置当前评分, 最大星数默认 5
rating->setRating(3);

// 评分变化时触发
connect(rating, &ElaRatingControl::ratingChanged, this, [=](int r) {
    qDebug() << "当前评分:" << r;
});

// 只读模式, 仅用于展示评分结果
ElaRatingControl* readOnlyRating = new ElaRatingControl(this);
readOnlyRating->setRating(4);
readOnlyRating->setIsReadOnly(true);
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `void setRating(int rating)` | 设置当前评分, 默认 0 |
| `int getRating() const` | 获取当前评分 |
| `void setMaxRating(int maxRating)` | 设置最大星数, 默认 5 |
| `void setStarSize(int starSize)` | 设置单颗星尺寸, 默认 24 |
| `void setSpacing(int spacing)` | 设置星与星之间的间距, 默认 4 |
| `void setIsReadOnly(bool isReadOnly)` | 设置只读模式, 默认 false |

**信号**:

- `ratingChanged(int rating)`: 评分变化

### ElaSelectorBar

分段选择条, 继承自 QWidget。一组水平排列的选项以滑动指示器标记当前选中项, 支持文本与图标加文本两种条目, 适用于视图切换、筛选分类等场景。

**头文件**: `#include "ElaSelectorBar.h"`

**基本用法**:

```cpp
#include "ElaSelectorBar.h"
#include "ElaDef.h"

// 纯文本选项
ElaSelectorBar* selectorBar = new ElaSelectorBar(this);
selectorBar->addItem("全部");
selectorBar->addItem("未读");
selectorBar->addItem("已标记");

// 图标加文本选项
ElaSelectorBar* viewSelector = new ElaSelectorBar(this);
viewSelector->addItem(ElaIconType::List, "列表");
viewSelector->addItem(ElaIconType::Grid2, "网格");

// 监听选中项变化
connect(selectorBar, &ElaSelectorBar::currentIndexChanged, this, [=](int index) {
    qDebug() << "当前选中索引:" << index;
});
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `void addItem(const QString& text)` | 添加纯文本选项 |
| `void addItem(ElaIconType::IconName icon, const QString& text)` | 添加带图标的选项 |
| `void clearItems()` | 清空全部选项 |
| `int getItemCount() const` | 获取选项数量 |
| `void setCurrentIndex(int currentIndex)` | 设置当前选中索引, 默认 0 |
| `int getCurrentIndex() const` | 获取当前选中索引 |
| `void setBorderRadius(int borderRadius)` | 设置圆角半径, 默认 4 |

**信号**:

- `currentIndexChanged(int index)`: 选中索引变化

**注意**:

- 图标枚举 `ElaIconType::IconName` 定义在 `ElaDef.h` 中。

### ElaTransfer

穿梭框, 继承自 QWidget。左右两个列表配合中间的移动按钮在源列表与目标列表之间转移条目, 内置搜索框与标题栏, 适用于权限分配、字段挑选等双列表选择场景。

**头文件**: `#include "ElaTransfer.h"`

**基本用法**:

```cpp
#include "ElaTransfer.h"

ElaTransfer* transfer = new ElaTransfer(this);
transfer->setFixedHeight(280);

// 设置两侧标题, 默认为 "源列表" / "目标列表"
transfer->setSourceTitle("可选项目");
transfer->setTargetTitle("已选项目");

// 填充源列表数据
QStringList items;
for (int i = 1; i <= 20; ++i) {
    items.append(QString("项目 %1").arg(i));
}
transfer->setSourceItems(items);

// 任意方向转移后触发
connect(transfer, &ElaTransfer::transferChanged, this,
        [=](const QStringList& sourceItems, const QStringList& targetItems) {
    qDebug() << "已选:" << targetItems.size() << "项";
});
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `void setSourceItems(const QStringList& items)` | 重置源列表数据 |
| `void addSourceItem(const QString& text)` | 向源列表追加单个条目 |
| `void addSourceItems(const QStringList& items)` | 向源列表批量追加条目 |
| `QStringList getSourceItems() const` | 获取源列表全部条目 |
| `QStringList getTargetItems() const` | 获取目标列表全部条目 |
| `void moveToTarget()` | 将源列表当前选中条目移入目标列表 |
| `void moveToSource()` | 将目标列表当前选中条目移回源列表 |
| `void moveAllToTarget()` | 将源列表全部条目移入目标列表 |
| `void moveAllToSource()` | 将目标列表全部条目移回源列表 |
| `void setSourceTitle(QString sourceTitle)` | 设置源列表标题, 默认 "源列表" |
| `void setTargetTitle(QString targetTitle)` | 设置目标列表标题, 默认 "目标列表" |
| `void setIsSearchVisible(bool isSearchVisible)` | 设置是否显示搜索框, 默认 true |
| `void setItemHeight(int itemHeight)` | 设置条目行高, 默认 35 |

**信号**:

- `transferChanged(const QStringList& sourceItems, const QStringList& targetItems)`: 条目转移完成, 携带两侧最新数据

**注意**:

- `moveToTarget()` / `moveToSource()` 只转移当前选中的条目, 未选中任何条目时调用不产生任何效果。

### ElaEmojiPicker

表情选择面板, 继承自 QWidget。以网格形式展示 emoji 表情, 通过 `popup` 接口在指定控件或坐标附近弹出, 选中后发出信号, 适用于聊天输入框等场景。

**头文件**: `#include "ElaEmojiPicker.h"`

**基本用法**:

```cpp
#include "ElaEmojiPicker.h"
#include "ElaLineEdit.h"
#include "ElaPushButton.h"

ElaEmojiPicker* emojiPicker = new ElaEmojiPicker(this);

ElaLineEdit* input = new ElaLineEdit(this);
ElaPushButton* emojiButton = new ElaPushButton("表情", this);

// 点击按钮时在按钮附近弹出面板
connect(emojiButton, &ElaPushButton::clicked, this, [=]() {
    emojiPicker->popup(emojiButton);
});

// 选中表情后插入输入框
connect(emojiPicker, &ElaEmojiPicker::emojiSelected, this, [=](const QString& emoji) {
    input->setText(input->text() + emoji);
});
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `void popup(QWidget* anchor)` | 在锚点控件附近弹出面板, 优先显示在上方, 空间不足时显示在下方 |
| `void popup(const QPoint& pos)` | 在指定全局坐标弹出面板 |
| `void setEmojiSize(int emojiSize)` | 设置单个表情尺寸, 默认 36 |
| `void setColumns(int columns)` | 设置网格列数, 默认 8 |

**信号**:

- `emojiSelected(const QString& emoji)`: 表情被选中, 参数为该表情的 Unicode 字符串

### ElaUploadArea

文件上传区域, 继承自 QWidget。支持拖拽文件与点击弹出文件对话框两种方式选择文件, 可按后缀、数量、大小做校验并拒绝不合规文件, 适用于文件上传表单。

**头文件**: `#include "ElaUploadArea.h"`

**基本用法**:

```cpp
#include "ElaUploadArea.h"

ElaUploadArea* uploadArea = new ElaUploadArea(this);
uploadArea->setFixedHeight(200);

// 限制允许的文件后缀、最大文件数
uploadArea->setAcceptedSuffixes({"png", "jpg", "jpeg", "pdf"});
uploadArea->setMaxFileCount(5);

// 自定义区域提示文案与文件对话框标题
uploadArea->setTitle("拖拽文件到此处");
uploadArea->setSubTitle("支持 png, jpg, pdf, 最多 5 个");
uploadArea->setDialogTitle("选择要上传的文件");

// 文件列表变化时触发
connect(uploadArea, &ElaUploadArea::filesSelected, this, [=](const QStringList& filePaths) {
    qDebug() << "已选择" << filePaths.size() << "个文件";
});

// 文件被拒绝时提示原因
connect(uploadArea, &ElaUploadArea::fileRejected, this,
        [=](const QString& filePath, const QString& reason) {
    qDebug() << "文件被拒绝:" << filePath << reason;
});
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `QStringList getSelectedFiles() const` | 获取当前已选择的文件路径列表 |
| `void clearFiles()` | 清空已选择的文件 |
| `void setAcceptedSuffixes(const QStringList& acceptedSuffixes)` | 设置允许的文件后缀白名单, 空列表表示不限制 |
| `void setMaxFileCount(int maxFileCount)` | 设置最大文件数量, 0 表示不限制, 默认 0 |
| `void setMaxFileSize(qint64 maxFileSize)` | 设置单个文件最大字节数, 0 表示不限制, 默认 0 |
| `void setIsMultiple(bool isMultiple)` | 设置是否允许一次选择多个文件, 默认 true |
| `void setTitle(const QString& title)` | 设置主提示文案, 默认 "拖拽文件到此处" |
| `void setSubTitle(const QString& subTitle)` | 设置副提示文案, 默认 "或点击选择文件" |
| `void setDialogTitle(const QString& dialogTitle)` | 设置点击弹出的文件对话框标题 |
| `void setAcceptedMimeFilter(const QString& filter)` | 设置文件对话框的 MIME 过滤器 |

**信号**:

- `filesSelected(const QStringList& filePaths)`: 已选文件列表变化, 携带完整列表
- `fileAdded(const QString& filePath)`: 单个文件通过校验被加入
- `fileRemoved(const QString& filePath)`: 单个文件被移除
- `fileRejected(const QString& filePath, const QString& reason)`: 文件未通过校验被拒绝, reason 为中文原因描述

**注意**:

- 后缀、数量、大小三项校验对拖拽与对话框两种入口同时生效, 被拒绝的文件通过 `fileRejected` 通知, 不会静默丢弃。
- 组件只负责收集本地文件路径, 实际上传动作由业务侧实现。

## 日期与滚轮选择

### ElaCalendar

FluentUI 风格的日历面板, 支持日, 月, 年三级视图切换与上下翻页, 适用于需要直接内嵌在页面中的日期浏览与选择场景。继承自 QWidget, 控件固定尺寸为 305x340。

**头文件**: `#include "ElaCalendar.h"`

**基本用法**:

```cpp
#include <QDate>
#include <QDebug>
#include "ElaCalendar.h"

// 创建日历面板, 内部已固定尺寸 305x340, 无需手动设置大小
ElaCalendar* calendar = new ElaCalendar(parentWidget);

// 设置初始选中日期
calendar->setSelectedDate(QDate::currentDate());

// 限制可选择的最大日期
calendar->setMaximumDate(QDate::currentDate().addYears(1));

// 用户点击某个日期时触发
QObject::connect(calendar, &ElaCalendar::clicked, [](QDate date) {
    qDebug() << "点击日期:" << date;
});
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `explicit ElaCalendar(QWidget* parent = nullptr)` | 构造日历面板 |
| `void setSelectedDate(QDate selectedDate)` | 设置选中日期, 无效日期或超出最小/最大日期范围时忽略 |
| `QDate getSelectedDate() const` | 获取当前选中日期 |
| `void setMinimumDate(QDate minimumDate)` | 设置可选择的最小日期 |
| `QDate getMinimumDate() const` | 获取可选择的最小日期 |
| `void setMaximumDate(QDate maximumDate)` | 设置可选择的最大日期 |
| `QDate getMaximumDate() const` | 获取可选择的最大日期 |
| `void setBorderRadius(int borderRadius)` | 设置面板圆角半径, 默认 5 |
| `int getBorderRadius() const` | 获取面板圆角半径 |

**信号**:

| 信号 | 说明 |
| --- | --- |
| `void clicked(QDate date)` | 用户在日视图中点击某个日期时发出 |
| `void pSelectedDateChanged()` | 选中日期变更时发出(属性变更信号) |

**注意**:

- 点击顶部的年月标题按钮可切换到月/年选择视图, 右侧两个箭头按钮用于翻页, 这些交互无需额外代码。
- `setSelectedDate` 传入无效日期或超出日期范围的值会被静默忽略, 不会抛错。

### ElaCalendarPicker

日期选择按钮, 点击后弹出 ElaCalendar 日历浮窗完成选择, 按钮上以 "年/月/日" 格式显示当前选中日期, 适用于表单中的日期输入。继承自 QPushButton, 控件固定尺寸为 120x30, 构造时默认选中当天日期。

**头文件**: `#include "ElaCalendarPicker.h"`

**基本用法**:

```cpp
#include <QDate>
#include <QDebug>
#include "ElaCalendarPicker.h"

// 创建日期选择按钮, 默认选中当天日期
ElaCalendarPicker* picker = new ElaCalendarPicker(parentWidget);

// 以编程方式设置选中日期
picker->setSelectedDate(QDate(2026, 1, 1));

// 无论通过弹窗选择还是调用 setSelectedDate, 日期变更都会触发该信号
QObject::connect(picker, &ElaCalendarPicker::selectedDateChanged, [](QDate date) {
    qDebug() << "选中日期:" << date;
});
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `explicit ElaCalendarPicker(QWidget* parent = nullptr)` | 构造日期选择按钮 |
| `void setSelectedDate(QDate selectedDate)` | 设置选中日期并发出 selectedDateChanged 信号 |
| `QDate getSelectedDate() const` | 获取当前选中日期 |
| `void setBorderRadius(int borderRadius)` | 设置按钮圆角半径, 默认 3 |
| `int getBorderRadius() const` | 获取按钮圆角半径 |

**信号**:

| 信号 | 说明 |
| --- | --- |
| `void selectedDateChanged(QDate date)` | 选中日期变更时发出, 弹窗内选择和调用 setSelectedDate 均会触发 |

**注意**:

- SelectedDate 由 `Q_PRIVATE_CREATE_Q_H` 宏生成, 没有 `pSelectedDateChanged` 属性信号, 监听日期变更必须使用 `selectedDateChanged(QDate)`。
- 按钮上的日期显示格式固定为 "年/月/日"(例如 2026/1/1), 不提供格式定制接口。
- 日期范围限制依赖内部 ElaCalendar 的默认范围, ElaCalendarPicker 自身未暴露最小/最大日期接口。

### ElaRoller

垂直滚轮选择器, 以滚轮滚动或点击条目的方式在一组字符串中选择一项, 中心高亮条指示当前选中项, 适用于数字, 时间等有序项的快捷选择。继承自 QWidget, 默认尺寸 90x175(条目高度 35 x 可见条目数 5)。

**头文件**: `#include "ElaRoller.h"`

**基本用法**:

```cpp
#include <QDebug>
#include <QStringList>
#include "ElaRoller.h"

// 创建滚轮并填充 1 到 100 的条目
ElaRoller* roller = new ElaRoller(parentWidget);
QStringList itemList;
for (int i = 0; i < 100; i++)
{
    itemList.append(QString::number(i + 1));
}
roller->setItemList(itemList);

// 以内容或索引方式设置当前项
roller->setCurrentData("50");
// roller->setCurrentIndex(49); // 与上一行等价

// 关闭循环滚动(默认开启)
roller->setIsEnableLoop(false);

// 滚动动画结束且选中项变化时触发
QObject::connect(roller, &ElaRoller::currentDataChanged, [](const QString& data) {
    qDebug() << "当前选中:" << data;
});
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `explicit ElaRoller(QWidget* parent = nullptr)` | 构造滚轮选择器 |
| `void setItemList(QStringList itemList)` | 设置条目列表 |
| `QStringList getItemList() const` | 获取条目列表 |
| `void setCurrentIndex(int currentIndex)` | 按索引设置当前项, 索引大于等于条目数时忽略(负数索引不做检查) |
| `int getCurrentIndex() const` | 获取当前项索引 |
| `void setCurrentData(const QString& data)` | 按内容设置当前项, 列表中不存在该内容时忽略 |
| `QString getCurrentData() const` | 获取当前项内容 |
| `void setItemHeight(int itemHeight)` | 设置单个条目高度, 默认 35, 修改后控件高度自动重算 |
| `int getItemHeight() const` | 获取单个条目高度 |
| `void setMaxVisibleItems(int maxVisibleItems)` | 设置可见条目数, 默认 5, 修改后控件高度自动重算 |
| `int getMaxVisibleItems() const` | 获取可见条目数 |
| `void setIsEnableLoop(bool isEnableLoop)` | 设置是否循环滚动, 默认 true |
| `bool getIsEnableLoop() const` | 获取是否循环滚动 |
| `void setBorderRadius(int borderRadius)` | 设置圆角半径, 默认 3 |

**信号**:

| 信号 | 说明 |
| --- | --- |
| `void currentDataChanged(const QString& data)` | 滚动动画结束且选中项发生变化时发出 |
| `void pCurrentIndexChanged()` | 滚动动画结束且选中索引变化时发出(属性变更信号); 调用 setCurrentIndex 不触发 |

**注意**:

- `currentDataChanged` 仅由用户交互(滚轮, 点击)引起的滚动在动画结束后发出; 调用 `setCurrentIndex` 或 `setCurrentData` 以编程方式设置当前项不会触发该信号。
- 控件高度由 "可见条目数 x 条目高度" 自动决定, 调用 `setItemHeight` 或 `setMaxVisibleItems` 后高度自动更新; 宽度默认固定 90, 需要更宽时调用 `setFixedWidth`。
- `IsContainer` 属性供 ElaRollerPicker 内部弹窗使用(透明背景并显示上下箭头), 常规独立使用保持默认值 false 即可。
- 点击中心以外的条目会滚动到该条目, 无需额外处理。

### ElaRollerPicker

多列滚轮选择按钮, 点击后弹出由多个 ElaRoller 列组成的浮窗, 底部带确认与取消按钮, 按钮表面实时显示各列当前值, 典型用途是时间选择(时/分, 时/分/AM-PM)。继承自 QPushButton, 高度固定 30, 宽度随各列宽度之和自动调整。

**头文件**: `#include "ElaRollerPicker.h"`

**基本用法**:

```cpp
#include <QDebug>
#include <QStringList>
#include <QTime>
#include "ElaRollerPicker.h"

// 创建时间选择器: 时 + 分 + AM/PM 三列
ElaRollerPicker* timePicker = new ElaRollerPicker(parentWidget);
QStringList hourItemList;
for (int i = 0; i < 24; i++)
{
    hourItemList.append(QString("%1").arg(i, 2, 10, QChar('0')));
}
QStringList minuteItemList;
for (int i = 0; i < 60; i++)
{
    minuteItemList.append(QString("%1").arg(i, 2, 10, QChar('0')));
}
timePicker->addRoller(hourItemList);          // 第 0 列: 小时, 默认循环滚动
timePicker->addRoller(minuteItemList);        // 第 1 列: 分钟
timePicker->addRoller({"AM", "PM"}, false);   // 第 2 列: 关闭循环滚动

// 设置各列宽度
timePicker->setRollerWidth(0, 90);
timePicker->setRollerWidth(1, 90);

// 按列内容批量设置当前值
QTime currentTime = QTime::currentTime();
timePicker->setCurrentData({QString("%1").arg(currentTime.hour(), 2, 10, QChar('0')),
                            QString("%1").arg(currentTime.minute(), 2, 10, QChar('0')),
                            currentTime.hour() >= 12 ? "PM" : "AM"});

// 用户在弹窗中点击确认按钮后触发
QObject::connect(timePicker, &ElaRollerPicker::currentDataChanged, [](const QStringList& dataList) {
    qDebug() << "确认选择:" << dataList;
});
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `explicit ElaRollerPicker(QWidget* parent = nullptr)` | 构造多列滚轮选择按钮 |
| `void addRoller(const QStringList& itemList, bool isEnableLoop = true)` | 追加一列滚轮, 空列表被忽略, isEnableLoop 控制该列是否循环滚动 |
| `void removeRoller(int index)` | 移除指定列, 索引大于等于列数时忽略(负数索引不做检查) |
| `void setRollerItemList(int index, const QStringList& itemList)` | 替换指定列的条目列表 |
| `void setRollerWidth(int index, int width)` | 设置指定列宽度, 控件总宽度随之自动更新 |
| `void setCurrentData(int index, const QString& data)` | 按内容设置指定列的当前值 |
| `void setCurrentData(const QStringList& dataList)` | 按内容批量设置各列当前值, 按列顺序对应 |
| `QString getCurrentData(int index) const` | 获取指定列的当前值 |
| `QStringList getCurrentData() const` | 获取所有列的当前值列表 |
| `void setCurrentIndex(int rollerIndex, int index)` | 按索引设置指定列的当前项 |
| `void setCurrentIndex(const QList<int>& indexList)` | 按索引批量设置各列当前项 |
| `int getCurrentIndex(int rollerIndex) const` | 获取指定列的当前索引, 列索引大于等于列数时返回 -1 |
| `QList<int> getCurrentIndex() const` | 获取所有列的当前索引列表 |
| `void setBorderRadius(int borderRadius)` | 设置按钮圆角半径, 默认 3 |

**信号**:

| 信号 | 说明 |
| --- | --- |
| `void currentDataChanged(const QStringList& dataList)` | 用户在弹窗中点击确认按钮时发出, 携带所有列的当前值 |
| `void currentDataSelectionChanged(const QStringList& dataList)` | 弹窗中任一列滚动动画结束且选中项变化时实时发出 |

**注意**:

- 以业务提交为目的时监听 `currentDataChanged`(确认后触发); 需要实时预览滚动结果时监听 `currentDataSelectionChanged`。
- 弹窗中的取消按钮会关闭弹窗并将各列回滚到弹窗打开时的选择; 未点击确认直接关闭弹窗(例如点击弹窗外部)同样会回滚, 只有点击确认按钮才保留滚动结果。
- 控件总宽度由各列宽度之和自动决定, `addRoller` / `removeRoller` / `setRollerWidth` 之后均会自动更新, 不要再手动 `setFixedWidth`。
- 各列在弹窗内固定为 7 个可见条目, 条目高度 35, 不提供修改接口。

## 数据展示: 状态与进度

### ElaText

主题感知的文本标签, 继承自 QLabel。内置 Fluent 排版预设 (Caption 到 Display 共 7 级), 也可以显示 ElaAwesome 字体图标, 是全库最常用的文本组件。

**头文件**: `#include "ElaText.h"`

**基本用法**:

```cpp
#include "ElaText.h"

// 标题文本: 使用排版预设 (Title = 28px DemiBold)
ElaText* title = new ElaText("仪表盘", this);
title->setTextStyle(ElaTextType::Title);

// 正文文本: 构造时直接指定像素大小
ElaText* body = new ElaText("这是一段正文说明文字", 13, this);

// 图标文本: 显示 ElaAwesome 图标 (代替文字内容)
ElaText* icon = new ElaText(this);
icon->setElaIcon(ElaIconType::House);
icon->setFixedSize(30, 30);
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `ElaText(QString text, QWidget* parent = nullptr)` | 构造并设置文本, 默认字号 28px |
| `ElaText(QString text, int pixelSize, QWidget* parent = nullptr)` | 构造并同时指定文本与像素字号 |
| `void setTextStyle(ElaTextType::TextStyle TextStyle)` | 设置排版预设: NoStyle / Caption(12) / Body(13) / BodyStrong(13 加粗) / Subtitle(20) / Title(28) / TitleLarge(40) / Display(48) |
| `ElaTextType::TextStyle getTextStyle() const` | 获取当前排版预设 |
| `void setTextPixelSize(int TextPixelSize)` | 按像素设置字号 |
| `void setTextPointSize(int TextPointSize)` | 按点设置字号 |
| `void setElaIcon(ElaIconType::IconName ElaIcon)` | 显示指定图标; 设置后文本内容不再绘制 |
| `void setIsWrapAnywhere(bool IsWrapAnywhere)` | 允许在任意字符处换行 (超长无空格文本) |

**注意**:

- 排版预设与 setTextPixelSize 都作用于同一 QFont, 后调用者生效。
- 文字颜色随 ElaTheme 明暗主题自动切换, 无需手动处理。
- 继承自 QLabel, setText / setAlignment 等 QLabel API 均可用。

### ElaInfoBadge

徽标组件, 附着在按钮等控件的右上角, 用于显示未读数量, 提示圆点或状态图标, 继承自 QWidget。

**头文件**: `#include "ElaInfoBadge.h"`

**基本用法**:

```cpp
#include "ElaInfoBadge.h"
#include "ElaPushButton.h"

// 数值徽标: 附着到目标控件右上角
ElaPushButton* mailButton = new ElaPushButton("邮件", this);
ElaInfoBadge* valueBadge = new ElaInfoBadge(5, this);
valueBadge->setSeverity(ElaInfoBadge::Informational);
valueBadge->attachTo(mailButton);
valueBadge->setValue(120); // 超过 MaxValue (默认 99) 时显示 "99+"

// 圆点徽标: 仅提示有新内容
ElaPushButton* noticeButton = new ElaPushButton("通知", this);
ElaInfoBadge* dotBadge = new ElaInfoBadge(this);
dotBadge->setBadgeMode(ElaInfoBadge::Dot);
dotBadge->setSeverity(ElaInfoBadge::Attention);
dotBadge->attachTo(noticeButton);

// 图标徽标
ElaPushButton* settingButton = new ElaPushButton("设置", this);
ElaInfoBadge* iconBadge = new ElaInfoBadge(ElaIconType::CircleExclamation, this);
iconBadge->setSeverity(ElaInfoBadge::Caution);
iconBadge->attachTo(settingButton);
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `ElaInfoBadge(int value, QWidget* parent = nullptr)` | 构造数值徽标 |
| `ElaInfoBadge(ElaIconType::IconName icon, QWidget* parent = nullptr)` | 构造图标徽标 |
| `void setBadgeMode(BadgeMode mode)` | 设置显示模式: Dot / Value_ / Icon |
| `void setValue(int Value)` | 设置数值 (Value_ 模式) |
| `void setMaxValue(int maxValue)` | 设置数值上限, 默认 99, 超出显示 "上限+" |
| `void setElaIcon(ElaIconType::IconName ElaIcon)` | 设置图标 (Icon 模式) |
| `void setSeverity(Severity severity)` | 设置严重等级配色: Attention / Informational / Success / Caution / Critical |
| `Severity getSeverity() const` | 获取当前严重等级 |
| `void attachTo(QWidget* target)` | 附着到目标控件右上角并跟随其移动和缩放 |

**注意**:

- attachTo 会把徽标 reparent 到目标控件并安装事件过滤器, 目标 Resize / Move 时自动重新定位并置顶。
- 数值模式的枚举名是 `Value_` (末尾带下划线)。

### ElaTag

标签组件, 用于展示分类或状态, 提供五种预设配色, 支持可关闭与可选中两种交互形态, 继承自 QWidget。

**头文件**: `#include "ElaTag.h"`

**基本用法**:

```cpp
#include "ElaTag.h"

// 预设配色标签
ElaTag* successTag = new ElaTag("Success", this);
successTag->setTagColor(ElaTag::Success); // Default / Primary / Success / Warning / Danger

// 可关闭标签: closed() 信号需自行处理隐藏或销毁
ElaTag* closableTag = new ElaTag("北京", this);
closableTag->setIsClosable(true);
connect(closableTag, &ElaTag::closed, this, [=]() { closableTag->hide(); });

// 可选中标签: 点击切换选中态
ElaTag* checkableTag = new ElaTag("周一", this);
checkableTag->setIsCheckable(true);
checkableTag->setIsChecked(true);
connect(checkableTag, &ElaTag::checkedChanged, this, [=](bool checked) {
    qDebug() << "标签选中状态:" << checked;
});
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `ElaTag(const QString& text, QWidget* parent = nullptr)` | 构造并设置标签文本 |
| `void setTagText(const QString& TagText)` | 设置标签文本 |
| `const QString& getTagText() const` | 获取标签文本 |
| `void setTagColor(TagColor color)` | 设置配色: Default / Primary / Success / Warning / Danger |
| `TagColor getTagColor() const` | 获取当前配色 |
| `void setIsClosable(bool IsClosable)` | 显示关闭按钮 |
| `void setIsCheckable(bool IsCheckable)` | 启用点击选中 |
| `void setIsChecked(bool IsChecked)` | 设置选中状态 |
| `bool getIsChecked() const` | 获取选中状态 |
| `void setBorderRadius(int BorderRadius)` | 设置圆角半径, 默认 4 |

**信号**:

| 信号 | 说明 |
| --- | --- |
| `void closed()` | 点击关闭按钮时发出 |
| `void clicked()` | 点击标签主体时发出 |
| `void checkedChanged(bool checked)` | 可选中标签的选中状态变化时发出 |

**注意**:

- closed() 只发出信号, 不会自动隐藏或销毁标签, 需在槽中自行 hide() 或 deleteLater()。
- 标签高度固定为 28, 宽度随文本自适应。

### ElaPersonPicture

圆形头像组件, 继承自 QWidget。按优先级显示三种内容: 头像图片 > 姓名首字母 (主题色底 + 白字) > 默认用户图标。

**头文件**: `#include "ElaPersonPicture.h"`

**基本用法**:

```cpp
#include "ElaPersonPicture.h"

// 图片头像: 自动按圆形裁剪
ElaPersonPicture* avatar = new ElaPersonPicture(this);
avatar->setPicture(QPixmap(":/Resource/Image/Cirno.jpg"));
avatar->setPictureSize(60);

// 首字母头像: 无图片时显示 DisplayName 前两个字符
ElaPersonPicture* initialsAvatar = new ElaPersonPicture(this);
initialsAvatar->setDisplayName("Ela");

// 默认头像: 既无图片也无名字时显示用户图标
ElaPersonPicture* defaultAvatar = new ElaPersonPicture(this);
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `ElaPersonPicture(QWidget* parent = nullptr)` | 构造头像, 默认尺寸 40x40 |
| `void setPictureSize(int PictureSize)` | 设置头像边长, 内部调用 setFixedSize |
| `int getPictureSize() const` | 获取头像边长 |
| `void setPicture(const QPixmap& Picture)` | 设置头像图片, 按圆形裁剪并保持比例填充 |
| `const QPixmap& getPicture() const` | 获取头像图片 |
| `void setDisplayName(QString DisplayName)` | 设置姓名, 无图片时取前两个字符作为首字母显示 |
| `QSize sizeHint() const` | 返回 PictureSize x PictureSize |

**注意**:

- 组件始终为正方形固定尺寸, 只能通过 setPictureSize 调整大小。
- 图片使用 Qt::KeepAspectRatioByExpanding 缩放, 非正方形图片会裁掉超出圆形的部分。

### ElaStatCard

统计卡片组件, 展示单个指标的标题, 数值, 趋势和补充说明, 适合仪表盘与数据概览页, 继承自 QWidget。

**头文件**: `#include "ElaStatCard.h"`

**基本用法**:

```cpp
#include "ElaStatCard.h"

// 完整的统计卡片: 标题 + 数值 + 图标 + 趋势
ElaStatCard* salesCard = new ElaStatCard(this);
salesCard->setTitle("今日销售额");
salesCard->setValue("86400");
salesCard->setCardIcon(ElaIconType::CartShopping);
salesCard->setTrend(ElaStatCard::Up);      // 上升趋势
salesCard->setTrendText("+15.3%");
salesCard->setDescription("较昨日");

// 中性趋势卡片
ElaStatCard* deviceCard = new ElaStatCard(this);
deviceCard->setTitle("在线设备");
deviceCard->setValue("1024");
deviceCard->setTrend(ElaStatCard::Neutral);
deviceCard->setTrendText("稳定");
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `void setTitle(const QString& Title)` | 设置指标标题 |
| `void setValue(const QString& Value)` | 设置指标数值 (字符串, 可含单位) |
| `void setDescription(const QString& Description)` | 设置补充说明文字 |
| `void setCardIcon(ElaIconType::IconName CardIcon)` | 设置卡片图标 |
| `void setBorderRadius(int BorderRadius)` | 设置卡片圆角半径 |
| `void setTrend(TrendType trend)` | 设置趋势类型: None / Up / Down / Neutral |
| `TrendType getTrend() const` | 获取趋势类型 |
| `void setTrendText(const QString& text)` | 设置趋势文本, 如 "+15.3%" |
| `QString getTrendText() const` | 获取趋势文本 |

**注意**:

- Value 是 QString 而非数值类型, 千分位, 货币符号, 百分号等格式需自行拼接。
- 多张卡片通常放入 QHBoxLayout 并列展示。

### ElaProgressBar

Fluent 风格进度条, 继承自 QProgressBar, 完整兼容其 API。当最小值与最大值同时为 0 时自动进入不确定进度的忙碌动画。

**头文件**: `#include "ElaProgressBar.h"`

**基本用法**:

```cpp
#include "ElaProgressBar.h"

// 确定进度: 直接使用 QProgressBar 接口
ElaProgressBar* bar = new ElaProgressBar(this);
bar->setMinimum(0);
bar->setMaximum(100);
bar->setValue(40);

// 忙碌态 (不确定进度): 最小值与最大值同时置 0
ElaProgressBar* busyBar = new ElaProgressBar(this);
busyBar->setMinimum(0);
busyBar->setMaximum(0);
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `void setMinimum(int minimum)` | 设置最小值; 与 setMaximum 均为 0 时进入忙碌动画 |
| `void setMaximum(int maximum)` | 设置最大值; 设为非零会退出忙碌动画 |
| `void setValue(int value)` | 设置当前进度 (继承自 QProgressBar) |
| `int value() const` | 获取当前进度 (继承自 QProgressBar) |
| `void setOrientation(Qt::Orientation)` | 设置水平或垂直方向 (继承自 QProgressBar) |
| `void setTextVisible(bool visible)` | 设置是否显示进度文本 (继承自 QProgressBar) |

**注意**:

- setMinimum / setMaximum 是对 QProgressBar 同名函数的隐藏 (非虚函数), 通过 QProgressBar* 基类指针调用不会触发忙碌态的切换逻辑, 应始终通过 ElaProgressBar 类型的指针操作。
- 退出忙碌态的方法是通过 ElaProgressBar::setMaximum 设置非零最大值。

### ElaProgressRing

圆环进度组件, 继承自 QWidget, 默认固定尺寸 70x70。支持确定进度与忙碌旋转两种形态, 环中心可显示实际值或百分比。

**头文件**: `#include "ElaProgressRing.h"`

**基本用法**:

```cpp
#include "ElaProgressRing.h"

// 确定进度环: 中心显示实际值
ElaProgressRing* ring = new ElaProgressRing(this);
ring->setRange(0, 100);
ring->setValue(30);

// 百分比显示模式
ElaProgressRing* percentRing = new ElaProgressRing(this);
percentRing->setValue(50);
percentRing->setValueDisplayMode(ElaProgressRingType::ValueDisplayMode::Percent);

// 忙碌态: 旋转动画, 透明底环
ElaProgressRing* busyRing = new ElaProgressRing(this);
busyRing->setIsBusying(true);
busyRing->setIsTransparent(true);
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `void setRange(int min, int max)` | 同时设置最小值与最大值 |
| `void setMinimum(int Minimum)` | 设置最小值, 默认 0 |
| `void setMaximum(int Maximum)` | 设置最大值, 默认 100 |
| `void setValue(int Value)` | 设置当前进度值 |
| `int getValue() const` | 获取当前进度值 |
| `void setIsBusying(bool IsBusying)` | 进入或退出忙碌旋转动画 |
| `void setIsTransparent(bool IsTransparent)` | 隐藏底环背景, 只绘制进度弧 |
| `void setIsDisplayValue(bool IsDisplayValue)` | 是否在环中心显示数值, 默认 true |
| `void setValueDisplayMode(ElaProgressRingType::ValueDisplayMode ValueDisplayMode)` | 数值显示模式: Actual (实际值) / Percent (百分比) |
| `void setValuePixelSize(int ValuePixelSize)` | 设置中心数值字号, 默认 17 |
| `void setBusyingWidth(int BusyingWidth)` | 设置圆环宽度, 默认 6 |
| `void setBusyingDurationTime(int BusyingDurationTime)` | 设置忙碌动画周期, 默认 1000 毫秒 |

**信号**:

| 信号 | 说明 |
| --- | --- |
| `void rangeChanged(int min, int max)` | 范围变化时发出 |
| `void pValueChanged()` | 进度值变化时发出 |

**注意**:

- 组件为固定尺寸 70x70, 需要更大的环可自行调用 setFixedSize。
- 忙碌态下不绘制进度值, 只显示旋转弧线。

### ElaSteps

横向步骤条组件, 继承自 QWidget, 固定高度 70。已完成步骤显示对勾, 当前步骤高亮显示序号, 未到达步骤显示灰色序号, 适合向导与多步流程。

**头文件**: `#include "ElaSteps.h"`

**基本用法**:

```cpp
#include "ElaSteps.h"
#include "ElaPushButton.h"

// 四步流程, 当前处于第二步 (索引从 0 开始)
ElaSteps* steps = new ElaSteps(this);
steps->setStepCount(4);
steps->setStepTitles({"选择商品", "确认订单", "支付", "完成"});
steps->setCurrentStep(1);

// 通过按钮驱动步骤前进后退
ElaPushButton* prevBtn = new ElaPushButton("上一步", this);
ElaPushButton* nextBtn = new ElaPushButton("下一步", this);
connect(prevBtn, &ElaPushButton::clicked, steps, &ElaSteps::previous);
connect(nextBtn, &ElaPushButton::clicked, steps, &ElaSteps::next);
connect(steps, &ElaSteps::currentStepChanged, this, [=](int step) {
    qDebug() << "当前步骤:" << step;
});
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `void setStepCount(int StepCount)` | 设置步骤总数, 默认 3 |
| `int getStepCount() const` | 获取步骤总数 |
| `void setCurrentStep(int CurrentStep)` | 设置当前步骤索引 (从 0 开始) |
| `int getCurrentStep() const` | 获取当前步骤索引 |
| `void setStepTitles(const QStringList& titles)` | 设置各步骤标题, 按索引对应 |
| `QStringList getStepTitles() const` | 获取步骤标题列表 |
| `void next()` | 前进一步, 到达最后一步后不再变化 |
| `void previous()` | 后退一步, 到达第一步后不再变化 |

**信号**:

| 信号 | 说明 |
| --- | --- |
| `void currentStepChanged(int step)` | next() / previous() 使步骤变化时发出 |

**注意**:

- CurrentStep 语义为 "正在进行的步骤索引", 其之前的所有步骤渲染为已完成。
- currentStepChanged(int) 仅由 next() / previous() 触发; 直接调用 setCurrentStep 触发的是属性信号 pCurrentStepChanged()。
- 标题数量少于 StepCount 时, 多出的步骤只显示序号不显示标题。

### ElaTimeline

垂直时间线组件, 继承自 QWidget, 按顺序展示事件序列, 每个条目包含标题, 内容, 时间戳和可选图标, 适合展示日志, 项目里程碑等。

**头文件**: `#include "ElaTimeline.h"`

**基本用法**:

```cpp
#include "ElaTimeline.h"

// 按时间顺序追加事件, TimelineItem 支持聚合初始化
ElaTimeline* timeline = new ElaTimeline(this);
timeline->addItem({"项目启动", "完成需求分析和技术选型", "2026-01-15", ElaIconType::RocketLaunch});
timeline->addItem({"开发阶段", "完成核心模块开发", "2026-02-20", ElaIconType::Code});
timeline->addItem({"测试阶段", "集成测试和验收测试", "2026-03-01"}); // 图标可省略
timeline->addItem({"发布上线", "部署到生产环境", "2026-03-15"});
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `void addItem(const TimelineItem& item)` | 追加一个时间线条目 |
| `void clearItems()` | 清空全部条目 |
| `int getItemCount() const` | 获取条目数量 |
| `TimelineItem::title` | 条目标题 (QString) |
| `TimelineItem::content` | 条目内容 (QString) |
| `TimelineItem::timestamp` | 时间戳文本 (QString, 原样显示不做解析) |
| `TimelineItem::icon` | 节点图标 (ElaIconType::IconName, 默认 ElaIconType::None 绘制普通节点) |

**注意**:

- timestamp 是纯文本, 组件不做排序, 条目按 addItem 顺序自上而下绘制。
- sizeHint 高度随条目数量增长, 条目较多时应放入 ElaScrollPage / QScrollArea 中使用。

### ElaSkeleton

骨架屏占位组件, 继承自 QWidget, 在数据加载完成前占住布局位置, 提供文本条, 圆形, 矩形三种形态和流光扫过动画。

**头文件**: `#include "ElaSkeleton.h"`

**基本用法**:

```cpp
#include "ElaSkeleton.h"

// 圆形骨架: 模拟头像占位
ElaSkeleton* circleSkeleton = new ElaSkeleton(this);
circleSkeleton->setSkeletonType(ElaSkeleton::Circle);
circleSkeleton->setFixedSize(40, 40);

// 文本条骨架: 模拟一行文字
ElaSkeleton* textSkeleton = new ElaSkeleton(this);
textSkeleton->setSkeletonType(ElaSkeleton::Text);
textSkeleton->setFixedSize(250, 16);

// 矩形骨架: 模拟卡片或图片, 可自定义圆角
ElaSkeleton* rectSkeleton = new ElaSkeleton(this);
rectSkeleton->setSkeletonType(ElaSkeleton::Rectangle);
rectSkeleton->setFixedSize(200, 80);
rectSkeleton->setBorderRadius(8);
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `void setSkeletonType(SkeletonType type)` | 设置形态: Text (文本条) / Circle (圆形) / Rectangle (矩形) |
| `SkeletonType getSkeletonType() const` | 获取当前形态 |
| `void setBorderRadius(int BorderRadius)` | 设置圆角半径, 默认 4, 仅对 Rectangle 形态生效 |
| `void setIsAnimated(bool IsAnimated)` | 开关流光动画, 默认 true |
| `bool getIsAnimated() const` | 获取动画开关状态 |

**注意**:

- sizeHint 为 protected, 仅供布局系统使用, 各形态默认尺寸: Text 200x16, Circle 40x40, Rectangle 200x100。
- 尺寸通过 setFixedSize 或布局控制; 设置 Circle 形态时组件会以当前宽度强制为正方形。
- Text 形态使用固定圆角 4, 自定义圆角只在 Rectangle 形态下有效。
- 数据就绪后自行隐藏或销毁骨架并换入真实控件, 组件本身不提供加载状态管理。

## 数据展示: 富内容

### ElaDivider

分隔线组件, 用于在页面中划分内容区块, 支持水平/垂直两种方向, 可选携带说明文字并控制文字位置。继承自 QWidget。

**头文件**: `#include "ElaDivider.h"`

**基本用法**:

```cpp
#include "ElaDivider.h"

// 默认水平分隔线
ElaDivider* divider = new ElaDivider(this);

// 带说明文字的分隔线, 文字默认居中
ElaDivider* textDivider = new ElaDivider("基础设置", this);
textDivider->setContentPosition(ElaDivider::Left); // 文字改为靠左

// 垂直分隔线, 放入水平布局中使用
ElaDivider* vDivider = new ElaDivider(this);
vDivider->setOrientation(Qt::Vertical);
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `ElaDivider(QWidget* parent = nullptr)` | 构造默认水平分隔线 |
| `ElaDivider(const QString& text, QWidget* parent = nullptr)` | 构造带说明文字的分隔线 |
| `void setOrientation(Qt::Orientation orientation)` | 设置方向, 默认 `Qt::Horizontal` |
| `Qt::Orientation getOrientation() const` | 获取当前方向 |
| `void setText(const QString& text)` | 设置分隔线上的说明文字 |
| `const QString& getText() const` | 获取说明文字 |
| `void setContentPosition(int contentPosition)` | 设置文字位置, 取值为 `ElaDivider::ContentPositionType` 枚举 (`Left` / `Center` / `Right`), 默认 `Center` |
| `int getContentPosition() const` | 获取文字位置 |

**注意**:

- `ContentPosition` 仅在设置了 `Text` 时生效; 垂直方向的分隔线不绘制文字。
- 组件实现了 `sizeHint()`, 直接加入布局即可获得合适的厚度, 无需手动指定高度或宽度。

### ElaLCDNumber

FluentUI 风格的 LCD 数码管显示组件, 在 QLCDNumber 基础上增加了自动时钟模式和透明背景支持, 适合仪表面板、时钟展示等场景。继承自 QLCDNumber, 父类的 `display()` 等接口均可直接使用。

**头文件**: `#include "ElaLCDNumber.h"`

**基本用法**:

```cpp
#include "ElaLCDNumber.h"

// 自动时钟模式: 按指定格式实时刷新当前时间
ElaLCDNumber* clock = new ElaLCDNumber(this);
clock->setIsUseAutoClock(true);
clock->setAutoClockFormat("hh:mm:ss"); // 默认格式为 "yyyy-MM-dd hh:mm:ss"
clock->setFixedHeight(100);

// 普通数码管模式: 直接调用父类 QLCDNumber 的 display()
ElaLCDNumber* number = new ElaLCDNumber(6, this);
number->display(3.14);
number->setIsTransparent(true); // 背景透明
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `ElaLCDNumber(QWidget* parent = nullptr)` | 构造默认数码管 |
| `ElaLCDNumber(uint numDigits, QWidget* parent = nullptr)` | 构造指定位数的数码管 |
| `void setIsUseAutoClock(bool isUseAutoClock)` | 开启/关闭自动时钟模式, 开启后按 `AutoClockFormat` 实时显示当前时间 |
| `bool getIsUseAutoClock() const` | 获取是否处于自动时钟模式 |
| `void setAutoClockFormat(QString autoClockFormat)` | 设置时钟格式字符串 (QDateTime 格式), 默认 `"yyyy-MM-dd hh:mm:ss"`, 同时自动调整显示位数 |
| `QString getAutoClockFormat() const` | 获取时钟格式字符串 |
| `void setIsTransparent(bool isTransparent)` | 设置背景是否透明 |
| `bool getIsTransparent() const` | 获取背景是否透明 |

**注意**:

- 设置 `AutoClockFormat` 会以格式字符串长度调用 `setDigitCount()`, 无需再手动设置位数。
- 自动时钟模式与手动 `display()` 互斥, 开启自动时钟后手动显示的内容会被时钟刷新覆盖。

### ElaCountdown

翻牌式倒计时组件, 以天/时/分/秒数字卡片展示剩余时间, 支持固定秒数与目标时间两种计时模式, 适合活动倒计时、限时任务等场景。继承自 QWidget。

**头文件**: `#include "ElaCountdown.h"`

**基本用法**:

```cpp
#include "ElaCountdown.h"

// 模式一: 固定剩余秒数
ElaCountdown* countdown = new ElaCountdown(this);
countdown->setRemainingSeconds(86400 + 3661); // 1 天 1 小时 1 分 1 秒
countdown->setIsShowDays(true);
countdown->start();

// 模式二: 倒计时到目标时间点
ElaCountdown* target = new ElaCountdown(this);
target->setIsShowDays(false); // 不显示天数卡片
target->setTargetDateTime(QDateTime::currentDateTime().addSecs(7200));
target->start();

// 每秒回调与结束回调
connect(countdown, &ElaCountdown::tick, this, [=](qint64 remainingSeconds) {
    qDebug() << "剩余秒数:" << remainingSeconds;
});
connect(countdown, &ElaCountdown::timeout, this, [=]() {
    qDebug() << "倒计时结束";
});
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `void setTargetDateTime(const QDateTime& dateTime)` | 设置倒计时目标时间点, 进入目标时间模式 |
| `QDateTime getTargetDateTime() const` | 获取目标时间点 |
| `void setRemainingSeconds(qint64 seconds)` | 设置剩余秒数, 进入固定秒数模式 |
| `qint64 getRemainingSeconds() const` | 获取当前剩余秒数 |
| `void start()` | 开始倒计时; 目标时间模式下会重新按当前时间计算剩余秒数 |
| `void pause()` | 暂停倒计时 |
| `void resume()` | 从暂停处继续 |
| `void stop()` | 停止并将剩余时间清零 |
| `bool isRunning() const` | 是否正在计时 (暂停后返回 false) |
| `void setIsShowDays(bool isShowDays)` | 是否显示天数卡片, 默认 true; 同类接口还有 `setIsShowHours` / `setIsShowMinutes` / `setIsShowSeconds` |
| `void setDigitWidth(int digitWidth)` | 设置单张数字卡片宽度, 默认 44 |
| `void setDigitHeight(int digitHeight)` | 设置单张数字卡片高度, 默认 56 |
| `void setDigitSpacing(int digitSpacing)` | 设置卡片间距, 默认 6 |
| `void setFontPixelSize(int fontPixelSize)` | 设置数字字号, 默认 24 |
| `void setBorderRadius(int borderRadius)` | 设置卡片圆角, 默认 6 |

**信号**:

- `void timeout()`: 倒计时归零时发出。
- `void tick(qint64 remainingSeconds)`: 每秒发出一次, 携带剩余秒数。

**注意**:

- `pause()` 后 `isRunning()` 返回 false, 恢复应调用 `resume()`; 对已在运行的组件重复调用 `start()` 无效果。
- `stop()` 会把剩余秒数清零, 重新计时前需要再次 `setRemainingSeconds()` 或 `setTargetDateTime()`。
- 组件尺寸由卡片宽高、间距和显示单元数量自动计算, 修改相关属性后无需手动调整尺寸。

### ElaQRCode

二维码组件, 将文本实时渲染为 QR Code, 支持四级纠错、前景/背景配色与静区宽度调整, 并可导出为 QPixmap。继承自 QWidget。

**头文件**: `#include "ElaQRCode.h"`

**基本用法**:

```cpp
#include "ElaQRCode.h"

// 构造时直接传入内容
ElaQRCode* qrCode = new ElaQRCode("https://github.com/RainbowCandyX/ElaWidgetTools", this);
qrCode->setFixedSize(180, 180);

// 动态更新内容与纠错等级
qrCode->setText("Hello ElaWidgetTools");
qrCode->setErrorCorrectionLevel(ElaQRCode::High); // 纠错等级越高, 容错越强

// 导出为图片保存
QPixmap pixmap = qrCode->toPixmap(512);
pixmap.save("qrcode.png");
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `ElaQRCode(QWidget* parent = nullptr)` | 构造空二维码 |
| `ElaQRCode(const QString& text, QWidget* parent = nullptr)` | 构造并直接编码指定文本 |
| `void setText(const QString& text)` | 设置编码内容, 立即重新生成二维码 |
| `QString getText() const` | 获取当前编码内容 |
| `void setErrorCorrectionLevel(ErrorCorrectionLevel level)` | 设置纠错等级, 枚举值为 `Low` / `Medium` / `Quartile` / `High` |
| `ErrorCorrectionLevel getErrorCorrectionLevel() const` | 获取纠错等级 |
| `QPixmap toPixmap(int size = 256) const` | 将二维码渲染为指定边长的 QPixmap |
| `void setQuietZone(int quietZone)` | 设置四周静区宽度 (以模块数计), 默认 2 |
| `void setForegroundColor(QColor foregroundColor)` | 设置前景色, 默认黑色 |
| `void setBackgroundColor(QColor backgroundColor)` | 设置背景色, 默认白色 |
| `void setBorderRadius(int borderRadius)` | 设置控件背景圆角, 默认 0 |

**注意**:

- 前景与背景需保持足够对比度, 否则扫码识别率下降; 静区 (`QuietZone`) 不建议设为 0。
- 控件本身不限制尺寸, 建议用 `setFixedSize()` 给定正方形尺寸以获得最佳显示效果。

### ElaDashboardGauge

仪表盘组件, 以圆弧刻度盘加数值文本的形式展示单一指标, 内置数值动画与警告/危险配色分区, 适合展示速度、CPU 占用率等实时指标。继承自 QWidget。

**头文件**: `#include "ElaDashboardGauge.h"`

**基本用法**:

```cpp
#include "ElaDashboardGauge.h"

ElaDashboardGauge* gauge = new ElaDashboardGauge(this);
gauge->setFixedSize(220, 220);
gauge->setMinimum(0);
gauge->setMaximum(200);
gauge->setValue(80);              // 内置动画平滑过渡到新值
gauge->setTitle("速度");           // 表盘标题
gauge->setUnit("km/h");           // 数值单位
gauge->setDecimals(2);            // 数值保留两位小数
gauge->setValuePixelSize(16);     // 数值字号
gauge->setTickWarningPercent(0.7); // 刻度从 70% 处开始使用警告色

// 数值变化回调
connect(gauge, &ElaDashboardGauge::valueChanged, this, [=](qreal value) {
    qDebug() << "当前值:" << value;
});
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `void setMinimum(qreal minimum)` | 设置量程最小值, 默认 0 |
| `void setMaximum(qreal maximum)` | 设置量程最大值, 默认 100 |
| `void setValue(qreal value)` | 设置当前值, 超出量程会被截断到 [Minimum, Maximum] |
| `qreal getValue() const` | 获取当前值 |
| `void setTitle(const QString& title)` | 设置表盘标题文本 |
| `void setUnit(const QString& unit)` | 设置数值单位文本 |
| `void setDecimals(int decimals)` | 设置数值显示的小数位数, 默认 0 |
| `void setIsAnimated(bool isAnimated)` | 是否启用数值过渡动画, 默认 true |
| `void setValuePixelSize(int valuePixelSize)` | 设置中央数值字号 |
| `void setStartAngle(int startAngle)` | 设置圆弧起始角度, 默认 225 |
| `void setSpanAngle(int spanAngle)` | 设置圆弧跨越角度, 默认 270 |
| `void setArcWidth(int arcWidth)` | 设置圆弧宽度, 默认 12 |
| `void setMajorTickCount(int majorTickCount)` | 设置主刻度数量, 默认 10 |
| `void setWarningPercent(qreal percent)` | 数值弧线进入警告色的百分比阈值 (0~1), 默认 0.65 |
| `void setDangerPercent(qreal percent)` | 数值弧线进入危险色的百分比阈值 (0~1), 默认 0.85 |

**信号**:

- `void valueChanged(qreal value)`: 当前值变化时发出。

**注意**:

- `WarningPercent` / `DangerPercent` 控制数值弧线的变色阈值; `setTickWarningPercent(qreal percent)` (默认 0.7) 单独控制刻度线开始变为警告色的位置, 两者相互独立。
- 阈值均为量程百分比而非绝对数值, 会被截断到 [0, 1]。

### ElaChatBubble

聊天气泡组件, 支持左右对齐、头像、发送者昵称、时间戳、消息状态与图片消息, 适合构建 IM 会话、AI 对话等界面。继承自 QWidget。

**头文件**: `#include "ElaChatBubble.h"`

**基本用法**:

```cpp
#include "ElaChatBubble.h"

// 对方消息: 左侧气泡
ElaChatBubble* left = new ElaChatBubble(this);
left->setDirection(ElaChatBubble::Left);
left->setSenderName("Alice");
left->setMessageText("你好! 最近在忙什么项目?");
left->setTimestamp("10:30");

// 自己的消息: 右侧气泡, 带已读状态
ElaChatBubble* right = new ElaChatBubble(this);
right->setDirection(ElaChatBubble::Right);
right->setSenderName("Bob");
right->setMessageText("在开发 ElaWidgetTools 的新组件!");
right->setTimestamp("10:31");
right->setStatus(ElaChatBubble::Read);

// 图片消息, 双击图片可获取原图
ElaChatBubble* imageBubble = new ElaChatBubble(this);
imageBubble->setDirection(ElaChatBubble::Right);
imageBubble->setMessageImage(QPixmap(":/Resource/Image/Cirno.jpg"));
imageBubble->setMessageText("看看这张图片!");
imageBubble->setStatus(ElaChatBubble::Sent);
connect(imageBubble, &ElaChatBubble::imageDoubleClicked, this, [=](const QPixmap& image) {
    // 在此弹出大图预览
});
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `void setDirection(BubbleDirection direction)` | 设置气泡方向, 枚举值为 `Left` / `Right` |
| `void setMessageText(const QString& messageText)` | 设置消息文本 |
| `void setSenderName(const QString& senderName)` | 设置发送者昵称, 为空则不显示 |
| `void setTimestamp(const QString& timestamp)` | 设置时间戳文本 |
| `void setStatus(MessageStatus status)` | 设置消息状态, 枚举值为 `None` / `Sending` / `Sent` / `Read` / `Failed` |
| `void setAvatar(const QPixmap& avatar)` | 设置头像图片 |
| `void setBubbleColor(const QColor& color)` | 自定义气泡背景色 |
| `void setMessageImage(const QPixmap& image)` | 设置图片消息内容 |
| `void setImageMaxWidth(int width)` | 设置图片消息的最大显示宽度 |
| `void setMaxBubbleWidth(int maxBubbleWidth)` | 设置气泡最大宽度, 默认 320, 超出自动换行 |
| `void setAvatarSize(int avatarSize)` | 设置头像尺寸, 默认 40 |
| `void setBorderRadius(int borderRadius)` | 设置气泡圆角, 默认 12 |

**信号**:

- `void imageDoubleClicked(const QPixmap& image)`: 双击图片消息时发出, 携带原始图片, 可用于弹出大图预览。

**注意**:

- 组件高度由内容自适应 (`sizeHint()` 已实现), 将多个气泡依次加入 QVBoxLayout 即可组成会话列表。
- 消息状态以文本形式绘制在气泡下方 (如 "已发送" / "已读"), 仅在 `Right` 方向 (自己发送的消息) 场景下有业务意义。

### ElaMarkdownViewer

Markdown 渲染组件, 将 Markdown 文本渲染为富文本页面, 支持标题、列表、代码块、引用和链接, 链接默认调用系统浏览器打开。继承自 QWidget, 内部基于 QTextBrowser 实现。

**头文件**: `#include "ElaMarkdownViewer.h"`

**基本用法**:

```cpp
#include "ElaMarkdownViewer.h"

ElaMarkdownViewer* viewer = new ElaMarkdownViewer(this);
viewer->setFixedHeight(200);
// 设置 Markdown 内容, 支持标题/列表/代码块/引用/链接
viewer->setMarkdown(
    "# ElaWidgetTools\n\n"
    "一个 **FluentUI** 风格的 Qt 组件库。\n\n"
    "- 支持 `Light` / `Dark` 主题切换\n"
    "- 跨平台: Windows / macOS / Linux\n\n"
    "```cpp\nElaToast::success(\"Hello World!\");\n```\n\n"
    "> 更多详情请访问 [GitHub](https://github.com/RainbowCandyX/ElaWidgetTools)\n");
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `ElaMarkdownViewer(QWidget* parent = nullptr)` | 构造 Markdown 渲染器 |
| `void setMarkdown(const QString& markdown)` | 设置 Markdown 源文本并立即渲染 |
| `const QString& getMarkdown() const` | 获取当前 Markdown 源文本 |
| `void setBorderRadius(int borderRadius)` | 设置背景圆角, 默认 0 |
| `int getBorderRadius() const` | 获取背景圆角 |

**注意**:

- 组件为只读展示用途, 不提供编辑能力; 需要展示代码并支持语法高亮时使用 ElaCodeEditor。
- 内容超出可视区域时内部自动出现滚动条, 外层布局中给定高度即可。

### ElaCodeEditor

代码编辑器组件, 提供行号显示与多语言语法高亮, 支持 C++/C/C#/Python/JavaScript/Lua/Rust/PHP 八种语言, 可作为编辑器或只读代码展示器使用。继承自 QWidget。

**头文件**: `#include "ElaCodeEditor.h"`

**基本用法**:

```cpp
#include "ElaCodeEditor.h"

ElaCodeEditor* editor = new ElaCodeEditor(this);
// 设置语言以启用对应语法高亮
editor->setLanguage(ElaCodeEditor::CPP);
// 填入代码文本
editor->setCode("#include <QApplication>\n\nint main(int argc, char* argv[])\n{\n    QApplication app(argc, argv);\n    return app.exec();\n}\n");
// 只读模式: 仅用于代码展示
editor->setIsReadOnly(true);
// Tab 宽度
editor->setTabSize(4);
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `ElaCodeEditor(QWidget* parent = nullptr)` | 构造代码编辑器 |
| `void setLanguage(Language lang)` | 设置高亮语言, 枚举值为 `CPP` / `C` / `CSharp` / `Python` / `JavaScript` / `Lua` / `Rust` / `PHP` |
| `Language getLanguage() const` | 获取当前高亮语言 |
| `void setCode(const QString& code)` | 设置编辑器中的代码文本 |
| `const QString& getCode() const` | 获取当前代码文本 |
| `void setIsReadOnly(bool isReadOnly)` | 设置是否只读 |
| `bool getIsReadOnly() const` | 获取是否只读 |
| `void setTabSize(int tabSize)` | 设置 Tab 宽度 (空格数) |
| `int getTabSize() const` | 获取 Tab 宽度 |

**注意**:

- 切换 `Language` 只影响高亮规则, 不会转换已有代码内容。
- 展示静态代码片段时建议开启 `setIsReadOnly(true)`, 避免用户误编辑。

### ElaTerminalWidget

终端模拟组件, 提供命令输入行、彩色输出区、命令历史 (上下方向键翻阅) 与 Tab 补全信号, 命令解析逻辑完全由使用方实现, 适合内嵌调试控制台、命令面板等场景。继承自 QWidget。

**头文件**: `#include "ElaTerminalWidget.h"`

**基本用法**:

```cpp
#include "ElaTerminalWidget.h"

ElaTerminalWidget* terminal = new ElaTerminalWidget(this);
terminal->setFixedHeight(300);
terminal->setPrompt("ela> ");                       // 默认提示符为 "$ "
terminal->appendSuccess("ElaTerminalWidget 已启动"); // 绿色成功文本
terminal->appendOutput("输入 help 查看可用命令");     // 普通输出

// 命令由使用方自行解析
connect(terminal, &ElaTerminalWidget::commandSubmitted, this, [=](const QString& cmd) {
    if (cmd == "clear")
    {
        terminal->clear();
    }
    else if (cmd.startsWith("echo "))
    {
        terminal->appendOutput(cmd.mid(5));
    }
    else
    {
        terminal->appendError("未知命令: " + cmd); // 红色错误文本
    }
});
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `void setPrompt(const QString& prompt)` | 设置命令提示符, 默认 `"$ "` |
| `void appendOutput(const QString& text, const QColor& color = QColor())` | 追加一行输出, 可指定文本颜色 |
| `void appendHtml(const QString& html)` | 追加一段 HTML 富文本输出 |
| `void appendError(const QString& text)` | 追加错误样式 (红色) 输出 |
| `void appendSuccess(const QString& text)` | 追加成功样式 (绿色) 输出 |
| `void clear()` | 清空输出区 |
| `QStringList getCommandHistory() const` | 获取命令历史列表 |
| `void setMaxHistorySize(int maxHistorySize)` | 设置命令历史容量, 默认 500 |
| `void setMaxLineCount(int maxLineCount)` | 设置输出区最大行数, 默认 5000, 超出后丢弃最早的行 |
| `void setFontPixelSize(int fontPixelSize)` | 设置终端字号, 默认 14 |

**信号**:

- `void commandSubmitted(const QString& command)`: 用户在输入行按回车提交命令时发出。
- `void tabPressed(const QString& currentInput)`: 用户按下 Tab 键时发出, 携带当前输入内容, 用于实现自定义补全。

**注意**:

- 组件本身不执行任何命令, 必须连接 `commandSubmitted` 实现命令处理, 否则输入回车后无响应。
- 输入行支持上下方向键翻阅历史命令。

### ElaWatermark

水印组件, 在父窗口上平铺绘制半透明的文字或图片水印, 自动跟随父窗口尺寸变化, 且不拦截鼠标事件, 适合防截图标识、版权声明等场景。继承自 QWidget。

**头文件**: `#include "ElaWatermark.h"`

**基本用法**:

```cpp
#include "ElaWatermark.h"

// 以顶层窗口为父对象, 水印自动铺满并跟随窗口缩放
ElaWatermark* watermark = new ElaWatermark("ElaWidgetTools", window());
watermark->setOpacity(0.12);   // 透明度, 默认 0.12
watermark->setRotation(-22);   // 倾斜角度, 默认 -22 度
watermark->setGapX(80);        // 水平间距, 默认 80
watermark->setGapY(60);        // 垂直间距, 默认 60
watermark->setFontPixelSize(14);

// 图片水印: 与文字可叠加使用
watermark->setImage(QImage(":/Resource/Image/logo.png"));
watermark->setImageWidth(48);
watermark->setImageHeight(48);

// 按需显示/隐藏
watermark->setVisible(true);
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `ElaWatermark(QWidget* parent = nullptr)` | 构造空水印, 通常传入顶层窗口作为 parent |
| `ElaWatermark(const QString& text, QWidget* parent = nullptr)` | 构造文字水印 |
| `void setText(const QString& text)` | 设置水印文字 |
| `void setFontPixelSize(int fontPixelSize)` | 设置文字字号, 默认 14 |
| `void setOpacity(qreal opacity)` | 设置整体透明度, 默认 0.12 |
| `void setRotation(qreal rotation)` | 设置倾斜角度 (度), 默认 -22 |
| `void setGapX(int gapX)` | 设置水印单元的水平间距, 默认 80 |
| `void setGapY(int gapY)` | 设置水印单元的垂直间距, 默认 60 |
| `void setTextColor(const QColor& textColor)` | 设置文字颜色; 未设置时跟随主题自动取色 |
| `void setImage(const QImage& image)` | 设置图片水印, 可与文字同时存在 |
| `void setImageWidth(int imageWidth)` | 设置图片显示宽度, 0 表示使用原始宽度 |
| `void setImageHeight(int imageHeight)` | 设置图片显示高度, 0 表示使用原始高度 |

**注意**:

- 构造时传入的 parent 决定水印覆盖范围: 组件会对 parent 安装事件过滤器, 自动跟随其尺寸变化并保持置顶, 推荐传入 `window()` 覆盖整个窗口。
- 水印设置了 `Qt::WA_TransparentForMouseEvents`, 不影响下层控件的任何交互。
- 若在水印创建之后又向父窗口添加了新的子控件, 新控件可能遮挡水印, 可再次调用 `raise()` 将水印提到最上层。

## 卡片

### ElaAcrylicUrlCard

亚克力材质的超链接卡片, 由半透明背板叠加噪声纹理构成, 上部为图片、下部为标题与副标题, 右下角带跳转图标。点击卡片时自动调用系统默认浏览器打开设置的 Url, 适合放置项目主页、社交链接等外部入口。继承自 QPushButton。

**头文件**: `#include "ElaAcrylicUrlCard.h"`

**基本用法**:

```cpp
#include <QPixmap>

#include "ElaAcrylicUrlCard.h"

ElaAcrylicUrlCard* urlCard = new ElaAcrylicUrlCard(this);
// 默认固定尺寸为 180x200, 可按需覆盖
urlCard->setFixedSize(195, 225);
// 卡片图片默认以 Ellipse 模式裁剪为圆形, 默认尺寸 54x54
urlCard->setCardPixmap(QPixmap(":/Resource/Image/github.png"));
urlCard->setCardPixmapSize(QSize(62, 62));
// 标题与副标题
urlCard->setTitle("ElaTool Github");
urlCard->setSubTitle("Use ElaWidgetTools To Create A Cool Project");
urlCard->setTitlePixelSize(17);
urlCard->setTitleSpacing(25);
urlCard->setSubTitleSpacing(13);
// 点击卡片时自动通过系统浏览器打开该链接
urlCard->setUrl("https://github.com/Liniyous/ElaWidgetTools");
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `void setUrl(QString Url)` | 设置点击卡片后打开的链接 |
| `QString getUrl() const` | 获取当前链接 |
| `void setTitle(QString Title)` | 设置标题文本 |
| `void setSubTitle(QString SubTitle)` | 设置副标题文本 |
| `void setTitlePixelSize(int TitlePixelSize)` | 设置标题字号, 默认 15 |
| `void setSubTitlePixelSize(int SubTitlePixelSize)` | 设置副标题字号, 默认 12 |
| `void setTitleSpacing(int TitleSpacing)` | 设置图片与标题的垂直间距, 默认 10 |
| `void setSubTitleSpacing(int SubTitleSpacing)` | 设置标题与副标题的垂直间距, 默认 10 |
| `void setCardPixmap(QPixmap CardPixmap)` | 设置卡片图片 |
| `void setCardPixmapSize(int width, int height)` | 设置图片绘制尺寸, 另有 `setCardPixmapSize(QSize CardPixmapSize)` 重载 |
| `void setCardPixMode(ElaCardPixType::PixMode CardPixMode)` | 设置图片裁剪模式, 默认 `Ellipse` |
| `void setCardPixmapBorderRadius(int CardPixmapBorderRadius)` | 设置 `RoundedRect` 模式下图片的圆角, 默认 6 |
| `void setBorderRadius(int BorderRadius)` | 设置卡片圆角, 默认 5 |
| `void setMainOpacity(qreal MainOpacity)` | 设置背板主体不透明度, 默认 0.95 |
| `void setNoiseOpacity(qreal NoiseOpacity)` | 设置噪声纹理不透明度, 默认 0.06 |

**信号**:

- `clicked()` (继承自 QPushButton): 点击卡片时发出。构造函数中已将该信号连接到打开 Url 的动作, 再次连接会与打开链接同时执行。

**注意**:

- `ElaCardPixType::PixMode` 定义在 `ElaDef.h` 中, 取值为 `Default` (原样绘制)、`RoundedRect` (圆角矩形裁剪)、`Ellipse` (椭圆裁剪)。
- 打开链接的行为是内置的, 无需手动连接 `clicked` 信号; 未设置 Url 时点击无跳转效果。
- 可配合 ElaToolTip 为卡片附加悬停提示, 示例工程中用其显示完整链接地址。

### ElaImageCard

圆角图片展示卡片, 将一张 QImage 以圆角矩形绘制并铺满整个控件, 支持保持宽高比居中裁剪或直接拉伸两种填充方式。常用作页面顶部背景横幅或头像图。继承自 QWidget。

**头文件**: `#include "ElaImageCard.h"`

**基本用法**:

```cpp
#include <QImage>

#include "ElaImageCard.h"

// 作为页面顶部背景横幅, 默认保持宽高比居中裁剪
ElaImageCard* backgroundCard = new ElaImageCard(this);
backgroundCard->setBorderRadius(10);
backgroundCard->setFixedHeight(340);
backgroundCard->setCardImage(QImage(":/Resource/Image/Home_Background.png"));

// 作为小尺寸头像图: 关闭等比裁剪, 图片直接拉伸填满卡片
ElaImageCard* pixCard = new ElaImageCard(this);
pixCard->setFixedSize(60, 60);
pixCard->setIsPreserveAspectCrop(false);
pixCard->setCardImage(QImage(":/Resource/Image/Moon.jpg"));
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `void setCardImage(QImage CardImage)` | 设置要展示的图片 |
| `QImage getCardImage() const` | 获取当前图片 |
| `void setBorderRadius(int BorderRadius)` | 设置卡片圆角, 默认 6 |
| `int getBorderRadius() const` | 获取卡片圆角 |
| `void setIsPreserveAspectCrop(bool IsPreserveAspectCrop)` | 设置是否保持宽高比居中裁剪, 默认 true |
| `bool getIsPreserveAspectCrop() const` | 获取当前填充方式 |

**注意**:

- `IsPreserveAspectCrop` 为 true 时, 按控件宽高比从图片中央裁剪后填充, 图片不变形; 为 false 时图片直接拉伸至控件大小。
- 默认最小尺寸为 350x260, 用作小图时需通过 `setFixedSize` 覆盖。
- 该组件可直接作为容器使用: 示例工程在背景卡片上安放 QVBoxLayout, 将标题文字与其他卡片叠加在图片之上。

### ElaInteractiveCard

水平布局的交互卡片, 左侧为图片(默认裁剪为圆形头像), 右侧为标题与副标题, 悬停时整卡高亮。库内 ElaNavigationBar 顶部的用户信息卡即为该组件, 适合个人信息入口、列表项等场景。继承自 QPushButton。

**头文件**: `#include "ElaInteractiveCard.h"`

**基本用法**:

```cpp
#include <QPixmap>

#include "ElaInteractiveCard.h"

ElaInteractiveCard* userCard = new ElaInteractiveCard(this);
// 图片默认以 Ellipse 模式裁剪为圆形, 默认尺寸 64x64
userCard->setCardPixmap(QPixmap(":/Resource/Image/Moon.jpg"));
userCard->setTitle("Ela User");
userCard->setSubTitle("user@example.com");
// 改用圆角矩形裁剪
userCard->setCardPixMode(ElaCardPixType::RoundedRect);
userCard->setCardPixmapBorderRadius(8);
// 继承自 QPushButton, 直接使用 clicked 信号
connect(userCard, &ElaInteractiveCard::clicked, this, [=]() {
    // 处理点击
});
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `void setTitle(QString Title)` | 设置标题文本 |
| `void setSubTitle(QString SubTitle)` | 设置副标题文本 |
| `void setTitlePixelSize(int TitlePixelSize)` | 设置标题字号, 默认 15 |
| `void setSubTitlePixelSize(int SubTitlePixelSize)` | 设置副标题字号, 默认 12 |
| `void setTitleSpacing(int TitleSpacing)` | 设置标题与副标题的垂直间距, 默认 2 |
| `void setCardPixmap(QPixmap CardPixmap)` | 设置卡片图片 |
| `void setCardPixmapSize(int width, int height)` | 设置图片绘制尺寸, 另有 `setCardPixmapSize(QSize CardPixmapSize)` 重载, 默认 64x64 |
| `void setCardPixMode(ElaCardPixType::PixMode CardPixMode)` | 设置图片裁剪模式, 默认 `Ellipse` |
| `void setCardPixmapBorderRadius(int CardPixmapBorderRadius)` | 设置 `RoundedRect` 模式下图片的圆角, 默认 6 |
| `void setBorderRadius(int BorderRadius)` | 设置卡片悬停高亮区域的圆角, 默认 6 |

**信号**:

- `clicked()` (继承自 QPushButton): 点击卡片时发出。

**注意**:

- 默认最小尺寸为 270x80, 无固定尺寸, 可自由拉伸。
- 使用 ElaWindow 时无需手动创建该组件, 导航栏用户信息卡已内置, 点击时 ElaWindow 会发出 `userInfoCardClicked` 信号。

### ElaPopularCard

应用商店风格的热门推荐卡片, 常态显示图片、标题、副标题与右下角提示标签; 悬停时卡片上浮, 停留约 450ms 后弹出浮窗, 展开显示详细介绍文本、附加图片与一个操作按钮。继承自 QWidget。

**头文件**: `#include "ElaPopularCard.h"`

**基本用法**:

```cpp
#include <QPixmap>

#include "ElaPopularCard.h"

ElaPopularCard* card = new ElaPopularCard(this);
card->setCardPixmap(QPixmap(":/Resource/Image/Cirno.jpg"));
card->setTitle("ElaWidgetTool");
card->setSubTitle("5.0 实用程序与工具");
// 右下角提示标签
card->setInteractiveTips("免费下载");
// 悬停浮窗中展开显示的详细介绍与附加图片
card->setDetailedText("ElaWidgetTools致力于为QWidget用户提供一站式的外观和实用功能解决方案");
card->setCardFloatPixmap(QPixmap(":/Resource/Image/IARC/IARC_7+.svg.png"));
// 浮窗中操作按钮的文本, 默认为"获取"
card->setCardButtonText("安装");
// 浮窗按钮点击
connect(card, &ElaPopularCard::popularCardButtonClicked, this, [=]() {
    // 例如打开下载页面
});
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `void setCardPixmap(QPixmap CardPixmap)` | 设置卡片左侧图片 |
| `void setTitle(QString Title)` | 设置标题文本 |
| `void setSubTitle(QString SubTitle)` | 设置副标题文本 |
| `void setInteractiveTips(QString InteractiveTips)` | 设置右下角提示标签文本, 如免费下载 |
| `void setDetailedText(QString DetailedText)` | 设置浮窗展开后显示的详细介绍 |
| `void setCardButtonText(QString cardButtonText)` | 设置浮窗操作按钮文本, 空字符串会被忽略 |
| `void setCardFloatPixmap(QPixmap CardFloatPixmap)` | 设置浮窗中显示的附加图片, 如分级图标 |
| `void setCardFloatArea(QWidget* floatArea)` | 设置浮窗的悬浮区域(父控件), 默认为 parentWidget() |
| `void setBorderRadius(int BorderRadius)` | 设置卡片圆角, 默认 8 |

**信号**:

- `popularCardClicked()`: 点击卡片本体时发出。
- `popularCardButtonClicked()`: 点击浮窗中的操作按钮时发出。

**注意**:

- 卡片为固定尺寸 320x120。
- 浮窗默认以 parentWidget() 为悬浮区域; 当卡片位于滚动区域等较小容器内时, 应通过 `setCardFloatArea` 指定更大的父级容器, 避免浮窗展开时被裁剪。传入 nullptr 或卡片自身会被忽略。
- 适合配合 ElaFlowLayout 构建卡片流布局, 示例工程首页的热门应用区即为此组合。

### ElaPromotionCard

大图促销卡片, 以一张背景图铺满卡片, 左上角绘制 CardTitle, 中部左侧为带半透明底色的 PromotionTitle 徽标与大号 Title, 其下为 SubTitle; 悬停有跟随鼠标的径向光晕, 点击有波纹扩散动画。可独立使用, 也可作为 ElaPromotionView 的轮播页。继承自 QWidget。

**头文件**: `#include "ElaPromotionCard.h"`

**基本用法**:

```cpp
#include <QPixmap>

#include "ElaPromotionCard.h"

ElaPromotionCard* promotionCard = new ElaPromotionCard(this);
promotionCard->setFixedSize(600, 300);
// 背景图铺满卡片
promotionCard->setCardPixmap(QPixmap(":/Resource/Image/Card/miku.png"));
// 左上角标题
promotionCard->setCardTitle("MiKu");
// 徽标文本, 绘制在 Title 上方并带半透明底色
promotionCard->setPromotionTitle("SONG~");
// 主标题与副标题
promotionCard->setTitle("STYX HELIX");
promotionCard->setSubTitle("Never close your eyes, Searching for a true fate");
// 点击卡片
connect(promotionCard, &ElaPromotionCard::promotionCardClicked, this, [=]() {
    // 处理点击
});
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `void setCardPixmap(QPixmap CardPixmap)` | 设置铺满卡片的背景图 |
| `void setCardTitle(QString CardTitle)` | 设置左上角标题, 默认字号 22 |
| `void setPromotionTitle(QString PromotionTitle)` | 设置徽标文本, 为空时不绘制, 默认字号 12 |
| `void setTitle(QString Title)` | 设置主标题, 默认字号 25 |
| `void setSubTitle(QString SubTitle)` | 设置副标题, 默认字号 16 |
| `void setCardTitleColor(QColor CardTitleColor)` | 设置左上角标题颜色, 默认白色 |
| `void setPromotionTitleColor(QColor PromotionTitleColor)` | 设置徽标文字颜色, 默认白色 |
| `void setPromotionTitleBaseColor(QColor PromotionTitleBaseColor)` | 设置徽标底色, 默认 QColor(0, 0, 0, 120) |
| `void setTitleColor(QColor TitleColor)` | 设置主标题颜色, 默认白色 |
| `void setSubTitleColor(QColor SubTitleColor)` | 设置副标题颜色, 默认白色 |
| `void setTitlePixelSize(int TitlePixelSize)` | 设置主标题字号, 同系列接口还有 `setCardTitlePixelSize` / `setPromotionTitlePixelSize` / `setSubTitlePixelSize` |
| `void setHorizontalCardPixmapRatio(qreal pixmapRatio)` | 设置背景图水平采样比例, 取值 (0, 1], 默认 1 |
| `void setVerticalCardPixmapRatio(qreal pixmapRatio)` | 设置背景图垂直采样比例, 取值 (0, 1], 默认 1 |
| `void setBorderRadius(int BorderRadius)` | 设置卡片圆角, 默认 5 |

**信号**:

- `promotionCardClicked()`: 鼠标在卡片上释放时发出。

**注意**:

- 文字默认全部为白色, 需搭配深色背景图使用; 浅色图片应通过颜色接口调整文字颜色。
- `HorizontalCardPixmapRatio` / `VerticalCardPixmapRatio` 控制从原图中央截取的比例, 值越小截取范围越小、画面放大越明显, 超出 (0, 1] 的值会被忽略。
- 卡片加入 ElaPromotionView 后, 其尺寸由视图接管, 无需再调用 setFixedSize。

### ElaPromotionView

促销卡片轮播视窗, 横向排列多张 ElaPromotionCard, 当前卡片展开显示、其余卡片折叠为窄条, 底部绘制指示圆点。点击折叠卡片或滚动鼠标滚轮可切换当前卡片, 支持定时自动轮播。继承自 QWidget。

**头文件**: `#include "ElaPromotionView.h"`

**基本用法**:

```cpp
#include <QPixmap>

#include "ElaPromotionCard.h"
#include "ElaPromotionView.h"

ElaPromotionView* promotionView = new ElaPromotionView(this);

// 创建若干张促销卡片并加入视图
ElaPromotionCard* card1 = new ElaPromotionCard(this);
card1->setCardPixmap(QPixmap(":/Resource/Image/Card/miku.png"));
card1->setCardTitle("MiKu");
card1->setPromotionTitle("SONG~");
card1->setTitle("STYX HELIX");
card1->setSubTitle("Never close your eyes, Searching for a true fate");
promotionView->appendPromotionCard(card1);

ElaPromotionCard* card2 = new ElaPromotionCard(this);
card2->setCardPixmap(QPixmap(":/Resource/Image/Card/beach.png"));
card2->setCardTitle("Beach");
card2->setTitle("STYX HELIX");
promotionView->appendPromotionCard(card2);

ElaPromotionCard* card3 = new ElaPromotionCard(this);
card3->setCardPixmap(QPixmap(":/Resource/Image/Card/dream.png"));
card3->setCardTitle("Dream");
card3->setTitle("STYX HELIX");
promotionView->appendPromotionCard(card3);

// 轮播间隔需在开启轮播前设置, 默认 5000ms
promotionView->setAutoScrollInterval(4000);
// 开启自动轮播
promotionView->setIsAutoScroll(true);
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `void appendPromotionCard(ElaPromotionCard* card)` | 追加一张促销卡片, 空指针或重复添加会被忽略, 视图会接管卡片的父对象与几何布局 |
| `void setCurrentIndex(int index)` | 切换到指定索引的卡片, 越界值会被忽略 |
| `int getCurrentIndex() const` | 获取当前展开卡片的索引 |
| `void setIsAutoScroll(bool isAutoScroll)` | 开启或关闭自动轮播, 默认关闭 |
| `void setAutoScrollInterval(int autoScrollInterval)` | 设置自动轮播间隔(毫秒), 小于 400 的值会被忽略, 默认 5000 |
| `void setCardExpandWidth(int width)` | 设置展开卡片宽度, 非正值会被忽略, 默认 600 |
| `void setCardCollapseWidth(int width)` | 设置折叠卡片宽度, 非正值会被忽略, 默认 300 |

**注意**:

- 自动轮播仅在卡片数量大于 2 且视图可见时生效。
- `setAutoScrollInterval` 不会重启已在运行的轮播定时器, 必须在 `setIsAutoScroll(true)` 之前调用才能生效。
- 视图在 resizeEvent 中按自身宽度自动重算展开/折叠宽度并调整视图高度(最小 200), 手动设置的 CardExpandWidth / CardCollapseWidth 会在尺寸变化时被覆盖, 通常无需手动设置。
- 滚轮切换内置 400ms 冷却时间, 防止连续快速翻页。
- 没有移除卡片的接口, 卡片集合应在初始化时一次性确定。

### ElaReminderCard

提醒卡片, 左侧为图片, 右侧为标题与副标题, 右上角绘制一个主题色圆点作为未读提示, 背板带阴影, 悬停时高亮。适合消息通知、更新提醒等入口。继承自 QPushButton。

**头文件**: `#include "ElaReminderCard.h"`

**基本用法**:

```cpp
#include <QPixmap>

#include "ElaReminderCard.h"

ElaReminderCard* reminderCard = new ElaReminderCard(this);
// 固定尺寸 330x105, 图片默认原样绘制(Default 模式), 尺寸 79x79
reminderCard->setCardPixmap(QPixmap(":/Resource/Image/Moon.jpg"));
reminderCard->setTitle("更新提醒");
reminderCard->setSubTitle("检测到新版本, 点击查看详情");
// 改为圆形裁剪
reminderCard->setCardPixMode(ElaCardPixType::Ellipse);
// 继承自 QPushButton, 直接使用 clicked 信号
connect(reminderCard, &ElaReminderCard::clicked, this, [=]() {
    // 处理点击
});
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `void setTitle(QString Title)` | 设置标题文本 |
| `void setSubTitle(QString SubTitle)` | 设置副标题文本 |
| `void setTitlePixelSize(int TitlePixelSize)` | 设置标题字号, 默认 15 |
| `void setSubTitlePixelSize(int SubTitlePixelSize)` | 设置副标题字号, 默认 12 |
| `void setTitleSpacing(int TitleSpacing)` | 设置标题与副标题的垂直间距, 默认 3 |
| `void setCardPixmap(QPixmap CardPixmap)` | 设置卡片图片 |
| `void setCardPixmapSize(int width, int height)` | 设置图片绘制尺寸, 另有 `setCardPixmapSize(QSize CardPixmapSize)` 重载, 默认 79x79 |
| `void setCardPixMode(ElaCardPixType::PixMode CardPixMode)` | 设置图片裁剪模式, 默认 `Default` |
| `void setCardPixmapBorderRadius(int CardPixmapBorderRadius)` | 设置 `RoundedRect` 模式下图片的圆角, 默认 6 |
| `void setBorderRadius(int BorderRadius)` | 设置卡片圆角, 默认 6 |

**信号**:

- `clicked()` (继承自 QPushButton): 点击卡片时发出。

**注意**:

- 构造函数中调用了 setFixedSize(330, 105), 如需其他尺寸可再次调用 setFixedSize 覆盖。
- 右上角的主题色圆点为固定绘制, 无开关接口, 不能按已读/未读状态隐藏。

## 导航与菜单

### ElaNavigationBar

Fluent 风格的侧边导航栏，支持页面节点、可展开分组节点、分类节点、底部节点、角标提示与用户信息卡，是构建多页面应用主框架的核心组件。继承自 QWidget。ElaWindow 内部已内置一个 ElaNavigationBar 并代理了它的全部节点接口，多数场景直接使用 ElaWindow 的同名方法即可；单独使用时需要自行响应节点点击信号完成页面切换。

**头文件**: `#include "ElaNavigationBar.h"`

**基本用法**:

```cpp
#include <QStackedWidget>
#include "ElaNavigationBar.h"

ElaNavigationBar* navigationBar = new ElaNavigationBar(this);

// 添加页面节点: 标题 + 页面控件 + 图标
QWidget* homePage = new QWidget(this);
navigationBar->addPageNode("主页", homePage, ElaIconType::House);

// 添加展开节点(分组), 并在其下挂载子页面
QString expanderKey;
navigationBar->addExpanderNode("数据管理", expanderKey, ElaIconType::List);
QWidget* tablePage = new QWidget(this);
navigationBar->addPageNode("表格", tablePage, expanderKey, ElaIconType::Table);

// 添加带角标(keyPoints)的页面节点, 角标显示数字 9
QWidget* messagePage = new QWidget(this);
navigationBar->addPageNode("消息", messagePage, 9, ElaIconType::Envelope);

// 添加底部节点, 常用于设置页
QString settingKey;
QWidget* settingPage = new QWidget(this);
navigationBar->addFooterNode("设置", settingPage, settingKey, 0, ElaIconType::GearComplex);

// 配置用户信息卡
navigationBar->setUserInfoCardVisible(true);
navigationBar->setUserInfoCardTitle("Ela Tool");
navigationBar->setUserInfoCardSubTitle("subTitle");

// 单独使用时自行处理页面切换; 配合 ElaWindow 使用时无需此步骤
connect(navigationBar, &ElaNavigationBar::navigationNodeClicked, this,
        [=](ElaNavigationType::NavigationNodeType nodeType, QString nodeKey, bool isRouteBack) {
            // 根据 nodeKey 切换对应页面
        });

// 页面节点的 key 保存在页面控件的 ElaPageKey 属性中, 可用于程序化跳转
navigationBar->navigation(homePage->property("ElaPageKey").toString());
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `ElaNavigationType::NodeResult addPageNode(const QString& pageTitle, QWidget* page, ElaIconType::IconName awesome = ElaIconType::None)` | 添加顶层页面节点，返回操作结果枚举 |
| `ElaNavigationType::NodeResult addPageNode(const QString& pageTitle, QWidget* page, const QString& targetExpanderKey, ElaIconType::IconName awesome = ElaIconType::None)` | 在指定展开节点下添加子页面节点 |
| `ElaNavigationType::NodeResult addExpanderNode(const QString& expanderTitle, QString& expanderKey, ElaIconType::IconName awesome = ElaIconType::None)` | 添加可展开分组节点，节点 key 通过出参 expanderKey 返回 |
| `ElaNavigationType::NodeResult addCategoryNode(const QString& categoryTitle, QString& categoryKey)` | 添加分类标题节点 |
| `ElaNavigationType::NodeResult addFooterNode(const QString& footerTitle, QWidget* page, QString& footerKey, int keyPoints = 0, ElaIconType::IconName awesome = ElaIconType::None)` | 添加底部节点并绑定页面，keyPoints 为角标数字 |
| `void removeNode(QString nodeKey)` | 按 key 移除节点 |
| `void navigation(QString pageKey, bool isLogClicked = true, bool isRouteBack = false)` | 程序化跳转到指定页面节点 |
| `void expandNode(QString expanderKey)` / `void collapseNode(QString expanderKey)` | 展开/折叠指定展开节点 |
| `void setNodeKeyPoints(QString nodeKey, int keyPoints)` | 设置节点角标数字，0 表示不显示 |
| `void setNodeTitle(QString nodeKey, QString nodeTitle)` | 修改节点标题 |
| `void setDisplayMode(ElaNavigationType::NavigationDisplayMode displayMode, bool isAnimation = true)` | 设置显示模式，可选 Auto / Minimal / Compact / Maximal |
| `void setUserInfoCardVisible(bool isVisible)` | 显示或隐藏顶部用户信息卡 |
| `void setUserInfoCardPixmap(QPixmap pix)` | 设置用户信息卡头像 |
| `void setUserInfoCardTitle(QString title)` / `void setUserInfoCardSubTitle(QString subTitle)` | 设置用户信息卡主标题/副标题 |
| `void setNavigationBarWidth(int)` / `int getNavigationBarWidth() const` | 设置/获取导航栏展开宽度 |

**信号**:

- `void navigationNodeClicked(ElaNavigationType::NavigationNodeType nodeType, QString nodeKey, bool isRouteBack)`: 节点被点击时发出
- `void navigationNodeAdded(ElaNavigationType::NavigationNodeType nodeType, QString nodeKey, QWidget* page)`: 节点添加成功时发出，可在此建立 nodeKey 与页面的映射
- `void navigationNodeRemoved(ElaNavigationType::NavigationNodeType nodeType, QString nodeKey)`: 节点被移除时发出
- `void userInfoCardClicked()`: 用户信息卡被点击时发出
- `void pageOpenInNewWindow(QString nodeKey)`: 页面请求在新窗口打开时发出，需先 `setIsAllowPageOpenInNewWindow(true)`

**注意**:

- 所有 add 系列接口返回 `ElaNavigationType::NodeResult`，包括 Success、TargetNodeInvalid、TargetNodeTypeError、TargetNodeDepthLimit、PageInvalid、FooterUpperLimit，建议检查返回值确认节点添加成功。
- 页面节点的 key 由组件内部生成，保存在页面控件的 `ElaPageKey` 动态属性中；展开节点、分类节点和底部节点的 key 通过接口的 `QString&` 出参返回。
- 底部节点数量有上限，超出时返回 `FooterUpperLimit`；展开节点嵌套深度有限制，超出时返回 `TargetNodeDepthLimit`。
- 使用 ElaWindow 时不需要手动创建 ElaNavigationBar，直接调用 ElaWindow 提供的同名代理接口即可。

### ElaBreadcrumbBar

面包屑导航栏，用于展示层级路径并支持点击回退，适合文件管理器、多级页面等场景。继承自 QWidget。

**头文件**: `#include "ElaBreadcrumbBar.h"`

**基本用法**:

```cpp
#include "ElaBreadcrumbBar.h"

ElaBreadcrumbBar* breadcrumbBar = new ElaBreadcrumbBar(this);

// 一次性设置完整路径
QStringList breadcrumbList;
breadcrumbList << "主页" << "文档" << "项目" << "源码";
breadcrumbBar->setBreadcrumbList(breadcrumbList);

// 追加一级路径
breadcrumbBar->appendBreadcrumb("子目录");

// 点击非末级面包屑时触发信号; 默认 IsAutoRemove 为 true,
// 点击后自动移除被点击项之后的所有层级
connect(breadcrumbBar, &ElaBreadcrumbBar::breadcrumbClicked, this,
        [=](QString breadcrumb, QStringList lastBreadcrumbList) {
            // breadcrumb 为被点击项文本, lastBreadcrumbList 为点击前的完整列表
        });
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `void setBreadcrumbList(QStringList breadcrumbList)` | 设置完整面包屑列表，覆盖现有内容 |
| `QStringList appendBreadcrumb(QString breadcrumb)` | 在末尾追加一级面包屑，返回追加后的列表 |
| `QStringList removeBreadcrumb(QString breadcrumb)` | 移除指定面包屑，返回移除后的列表 |
| `QStringList getBreadcrumbList() const` | 获取当前面包屑列表 |
| `int getBreadcrumbListCount() const` | 获取当前面包屑数量 |
| `void setTextPixelSize(int)` / `int getTextPixelSize() const` | 设置/获取文本像素大小 |
| `void setIsAutoRemove(bool)` / `bool getIsAutoRemove() const` | 设置点击后是否自动移除后续层级，默认 true |

**信号**:

- `void breadcrumbClicked(QString breadcrumb, QStringList lastBreadcrumbList)`: 面包屑被点击时发出，携带被点击项文本与点击前的完整列表

**注意**:

- `IsAutoRemove` 为 true 时，点击末级(当前级)面包屑不会触发 `breadcrumbClicked` 信号，只有点击前面的层级才会触发并裁剪路径；为 false 时点击任意项都会触发信号且不修改列表。
- 面包屑过多超出宽度时支持鼠标左键拖拽横向滚动。

### ElaPivot

Fluent 风格的枢轴导航(文本选项卡)，以纯文本加下划线标记的形式在少量视图之间切换，常见于音乐、下载类页面的顶部分类切换。继承自 QWidget。

**头文件**: `#include "ElaPivot.h"`

**基本用法**:

```cpp
#include "ElaPivot.h"

ElaPivot* pivot = new ElaPivot(this);
pivot->setPivotSpacing(8);   // 项间距
pivot->setMarkWidth(75);     // 底部选中标记宽度
pivot->appendPivot("本地歌曲");
pivot->appendPivot("下载歌曲");
pivot->appendPivot("下载视频");
pivot->setCurrentIndex(0);   // 默认选中第一项

// 点击切换时同步切换内容区域
connect(pivot, &ElaPivot::pivotClicked, this, [=](int index) {
    // 根据 index 切换 QStackedWidget 等内容视图
});
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `void appendPivot(QString pivotTitle)` | 追加一个枢轴项 |
| `void removePivot(QString pivotTitle)` | 按标题移除枢轴项 |
| `void setCurrentIndex(int)` / `int getCurrentIndex() const` | 设置/获取当前选中项索引 |
| `void setTextPixelSize(int)` / `int getTextPixelSize() const` | 设置/获取文本像素大小，默认 20 |
| `void setPivotSpacing(int)` / `int getPivotSpacing() const` | 设置/获取项之间的间距 |
| `void setMarkWidth(int)` / `int getMarkWidth() const` | 设置/获取选中项底部标记的宽度 |

**信号**:

- `void pivotClicked(int index)`: 枢轴项被点击时发出
- `void pivotDoubleClicked(int index)`: 枢轴项被双击时发出
- `void pCurrentIndexChanged()`: 选中索引变化时发出

**注意**:

- 组件固定高度 40 像素，项过多超出宽度时支持鼠标左键拖拽横向滚动。
- ElaPivot 只负责导航标记本身，不管理内容页面，需要配合 QStackedWidget 等容器自行切换内容。

### ElaTabBar

Fluent 风格标签栏，在 QTabBar 基础上增加了标签拖拽分离与跨窗口拖拽能力，是 ElaTabWidget 的内部标签栏，也可以单独使用。继承自 QTabBar。

**头文件**: `#include "ElaTabBar.h"`

**基本用法**:

```cpp
#include "ElaTabBar.h"

ElaTabBar* tabBar = new ElaTabBar(this);
// 构造时已默认开启: setTabsClosable(true)、setMovable(true)、setAcceptDrops(true)

// QTabBar 原生接口均可使用
tabBar->addTab("标签一");
tabBar->addTab("标签二");
tabBar->setTabSize(QSize(140, 36)); // 统一标签尺寸

// 关闭按钮点击
connect(tabBar, &QTabBar::tabCloseRequested, this, [=](int index) {
    tabBar->removeTab(index);
});
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `explicit ElaTabBar(QWidget* parent = nullptr)` | 构造函数，默认开启可关闭、可拖动、接受拖放 |
| `void setTabSize(QSize)` / `QSize getTabSize() const` | 设置/获取单个标签的固定尺寸 |

**信号**:

- `void tabDragCreate(QMimeData* mimeData)`: 标签被拖出标签栏时发出
- `void tabDragEnter(QMimeData* mimeData)`: 外部标签拖拽进入时发出
- `void tabDragLeave(QMimeData* mimeData)`: 拖拽离开时发出
- `void tabDragDrop(QMimeData* mimeData)`: 标签在本标签栏落下时发出

**注意**:

- 除上表接口外，addTab、removeTab、setCurrentIndex 等接口继承自 QTabBar，可直接使用。
- 四个拖拽信号主要供 ElaTabWidget 内部联动使用，实现标签拖出成窗与跨窗口拖拽；一般业务代码直接使用 ElaTabWidget 即可，无需手动处理这些信号。

### ElaTabWidget

Fluent 风格多标签页容器，内置 ElaTabBar，支持将标签拖出生成独立浮动窗口、在多个 ElaTabWidget 之间拖拽转移标签。继承自 QTabWidget。

**头文件**: `#include "ElaTabWidget.h"`

**基本用法**:

```cpp
#include "ElaTabWidget.h"

ElaTabWidget* tabWidget = new ElaTabWidget(this);
tabWidget->setIsTabTransparent(true); // 标签页背景透明, 融入页面底色

// QTabWidget 原生接口添加页面
QWidget* page1 = new QWidget(this);
tabWidget->addTab(page1, QIcon(":/Resource/Image/Cirno.jpg"), "新标签页");
QWidget* page2 = new QWidget(this);
tabWidget->addTab(page2, "新标签页2");

// 允许其他 ElaTabWidget 的标签直接拖入本容器的内容区域
tabWidget->setIsContainerAcceptDrops(true);

// 统一标签尺寸
tabWidget->setTabSize(QSize(140, 36));
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `void setTabPosition(TabPosition position)` | 设置标签位置，仅 QTabWidget::North 和 QTabWidget::South 生效 |
| `void setIsTabTransparent(bool)` / `bool getIsTabTransparent() const` | 设置/获取标签页背景是否透明，默认 false |
| `void setIsContainerAcceptDrops(bool)` / `bool getIsContainerAcceptDrops() const` | 设置/获取内容区域是否接受其他 ElaTabWidget 的标签拖入，默认 false |
| `void setTabSize(QSize)` / `QSize getTabSize() const` | 设置/获取单个标签的固定尺寸，转发给内部 ElaTabBar |

**注意**:

- 标签默认可关闭、可拖动排序；将标签拖出窗口会自动生成独立的浮动标签窗口，再拖回可合并，无需编写任何代码。
- `setTabPosition` 传入 East/West 会被忽略，该组件只支持上下两种标签位置。
- addTab、removeTab、setCurrentIndex 等页面管理接口继承自 QTabWidget。

### ElaMenu

Fluent 风格弹出菜单，在 QMenu 基础上提供图标 Action、子菜单和菜单项高度定制，适合上下文菜单、按钮下拉菜单等场景。继承自 QMenu。

**头文件**: `#include "ElaMenu.h"`

**基本用法**:

```cpp
#include "ElaMenu.h"

ElaMenu* menu = new ElaMenu(this);
menu->setMenuItemHeight(27); // 菜单项高度

// 带 Fluent 图标的 Action, 可附加快捷键
menu->addElaIconAction(ElaIconType::Copy, "复制");
menu->addElaIconAction(ElaIconType::BoxCheck, "排序方式", QKeySequence::SelectAll);
menu->addSeparator();

// 普通 Action 与信号连接
connect(menu->addAction("刷新"), &QAction::triggered, this, [=]() {
    // 处理刷新
});

// 带图标的子菜单
ElaMenu* subMenu = menu->addMenu(ElaIconType::Aperture, "更多操作");
subMenu->addElaIconAction(ElaIconType::ArrowRotateLeft, "撤销");

// 在鼠标位置弹出
// menu->popup(QCursor::pos());
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `explicit ElaMenu(const QString& title, QWidget* parent = nullptr)` | 以标题构造菜单，可作为子菜单加入其他菜单 |
| `void setMenuItemHeight(int menuItemHeight)` / `int getMenuItemHeight() const` | 设置/获取菜单项高度 |
| `QAction* addElaIconAction(ElaIconType::IconName icon, const QString& text)` | 添加带 Fluent 图标的 Action |
| `QAction* addElaIconAction(ElaIconType::IconName icon, const QString& text, const QKeySequence& shortcut)` | 添加带图标和快捷键的 Action |
| `ElaMenu* addMenu(const QString& title)` | 添加文本子菜单，返回新建的 ElaMenu |
| `ElaMenu* addMenu(ElaIconType::IconName icon, const QString& title)` | 添加带 Fluent 图标的子菜单 |
| `QAction* addMenu(QMenu* menu)` | 添加已有的 QMenu/ElaMenu 作为子菜单 |
| `bool isHasChildMenu() const` | 是否包含子菜单 |
| `bool isHasIcon() const` | 是否存在带图标的菜单项 |

**信号**:

- `void menuShow()`: 菜单显示时发出

**注意**:

- addAction、addSeparator、popup、exec 等接口继承自 QMenu，可直接使用。
- ElaMenu 可传入 ElaToolButton::setMenu 作为按钮下拉菜单，也可传入 ElaWindow::setCustomMenu 作为标题栏右键菜单。

### ElaMenuBar

Fluent 风格菜单栏，在 QMenuBar 基础上提供 ElaMenu 子菜单与图标 Action 的便捷添加接口。继承自 QMenuBar。

**头文件**: `#include "ElaMenuBar.h"`

**基本用法**:

```cpp
#include "ElaMenuBar.h"
#include "ElaMenu.h"

ElaMenuBar* menuBar = new ElaMenuBar(this);
menuBar->setFixedHeight(30);

// 直接添加带图标的顶层 Action
menuBar->addElaIconAction(ElaIconType::AtomSimple, "动作菜单");

// 添加带图标的下拉菜单
ElaMenu* iconMenu = menuBar->addMenu(ElaIconType::Aperture, "图标菜单");
iconMenu->setMenuItemHeight(27);
iconMenu->addElaIconAction(ElaIconType::Copy, "复制");
iconMenu->addSeparator();
iconMenu->addElaIconAction(ElaIconType::ArrowRotateRight, "刷新");

// 支持助记符的文本菜单
menuBar->addMenu("样例菜单(&B)")->addElaIconAction(ElaIconType::ArrowRotateRight, "样例选项");
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `ElaMenu* addMenu(const QString& title)` | 添加文本下拉菜单，返回新建的 ElaMenu |
| `ElaMenu* addMenu(const QIcon& icon, const QString& title)` | 添加带 QIcon 图标的下拉菜单 |
| `ElaMenu* addMenu(ElaIconType::IconName, const QString& title)` | 添加带 Fluent 图标的下拉菜单 |
| `QAction* addMenu(QMenu* menu)` | 添加已有的 QMenu/ElaMenu |
| `QAction* addElaIconAction(ElaIconType::IconName icon, const QString& text)` | 添加带 Fluent 图标的顶层 Action |
| `QAction* addElaIconAction(ElaIconType::IconName icon, const QString& text, const QKeySequence& shortcut)` | 添加带图标和快捷键的顶层 Action |

**注意**:

- 在 ElaWindow 中使用时，示例工程的做法是将菜单栏包装进自定义控件后调用 `setCustomWidget(ElaAppBarType::MiddleArea, customWidget)` 嵌入标题栏中部区域；使用 QMainWindow 时可直接 `setMenuBar(menuBar)`。
- addSeparator 等其余接口继承自 QMenuBar。

### ElaCommandBar

Fluent 风格命令栏，以一行图标加文字按钮的形式承载高频操作，空间不足时自动把放不下的项收纳到溢出菜单中，适合作页面顶部的操作条。继承自 QWidget。

**头文件**: `#include "ElaCommandBar.h"`

**基本用法**:

```cpp
#include "ElaCommandBar.h"

ElaCommandBar* commandBar = new ElaCommandBar(this);

// CommandItem 结构: { 图标, 文本, 是否分隔符 }
commandBar->addItem({ElaIconType::Copy, "复制"});
commandBar->addItem({ElaIconType::Paste, "粘贴"});
commandBar->addItem({ElaIconType::Scissors, "剪切"});
commandBar->addSeparator();
commandBar->addItem({ElaIconType::ArrowRotateLeft, "撤销"});
commandBar->addItem({ElaIconType::ArrowRotateRight, "重做"});
commandBar->addSeparator();
commandBar->addItem({ElaIconType::FloppyDisk, "保存"});

// index 为按添加顺序的下标(分隔符也占用一个下标)
connect(commandBar, &ElaCommandBar::itemClicked, this, [=](int index) {
    // 根据 index 分发对应命令
});
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `void addItem(const CommandItem& item)` | 添加一个命令项，CommandItem 含 icon、text、isSeparator 三个字段 |
| `void addSeparator()` | 添加分隔符 |
| `void clearItems()` | 清空全部命令项 |
| `void setButtonSize(int)` / `int getButtonSize() const` | 设置/获取按钮尺寸，默认 36 |

**信号**:

- `void itemClicked(int index)`: 命令项被点击时发出，index 为该项在添加顺序中的下标，分隔符也计入下标

**注意**:

- 宽度不足以显示全部项时，末尾自动出现省略按钮，点击后以 ElaMenu 弹出被收纳的命令项，溢出菜单中的项点击后同样发出 `itemClicked`，下标保持一致。
- 处理 `itemClicked` 时注意分隔符占位，建议在添加命令时记录各命令对应的下标。

### ElaToolBar

Fluent 风格工具栏，在 QToolBar 基础上增加了按钮间距、按钮尺寸和 Fluent 图标 Action 的定制能力，配合 QMainWindow(或 ElaWindow)的工具栏区域使用，支持拖动与浮动。继承自 QToolBar。

**头文件**: `#include "ElaToolBar.h"`

**基本用法**:

```cpp
#include "ElaToolBar.h"
#include "ElaToolButton.h"

ElaToolBar* toolBar = new ElaToolBar("工具栏", this);
toolBar->setAllowedAreas(Qt::TopToolBarArea | Qt::BottomToolBarArea);
toolBar->setToolBarSpacing(3);            // 按钮间距
toolBar->setToolButtonStyle(Qt::ToolButtonIconOnly);
toolBar->setIconSize(QSize(25, 25));

// 添加 ElaToolButton 作为工具按钮
ElaToolButton* toolButton = new ElaToolButton(this);
toolButton->setElaIcon(ElaIconType::BadgeCheck);
toolBar->addWidget(toolButton);
toolBar->addSeparator();

// 直接添加带 Fluent 图标的 Action
toolBar->addElaIconAction(ElaIconType::ArrowRotateRight, "刷新");

// 挂载到主窗口顶部工具栏区域
this->addToolBar(Qt::TopToolBarArea, toolBar);
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `explicit ElaToolBar(const QString& title, QWidget* parent = nullptr)` | 以标题构造工具栏，标题用于浮动窗口与右键菜单 |
| `void setToolBarSpacing(int spacing)` / `int getToolBarSpacing() const` | 设置/获取工具栏内控件间距 |
| `void setToolButtonSize(const QSize& size)` / `const QSize& getToolButtonSize() const` | 设置/获取工具按钮的统一尺寸 |
| `QAction* addElaIconAction(ElaIconType::IconName icon, const QString& text)` | 添加带 Fluent 图标的 Action |
| `QAction* addElaIconAction(ElaIconType::IconName icon, const QString& text, const QKeySequence& shortcut)` | 添加带图标和快捷键的 Action |

**注意**:

- setAllowedAreas、setMovable、setFloatable、addWidget、addSeparator 等接口继承自 QToolBar。
- ElaWindow 继承自 QMainWindow，可直接调用 `addToolBar` 挂载 ElaToolBar。

### ElaStatusBar

Fluent 风格状态栏，对 QStatusBar 做了主题化样式适配，用法与 QStatusBar 完全一致，用于主窗口底部展示状态信息。继承自 QStatusBar。

**头文件**: `#include "ElaStatusBar.h"`

**基本用法**:

```cpp
#include "ElaStatusBar.h"
#include "ElaText.h"

ElaStatusBar* statusBar = new ElaStatusBar(this);

// 添加常驻状态控件
ElaText* statusText = new ElaText("初始化成功！", this);
statusText->setTextPixelSize(14);
statusBar->addWidget(statusText);

// 挂载到主窗口底部
this->setStatusBar(statusBar);

// 也可显示临时消息(继承自 QStatusBar), 显示 3 秒
statusBar->showMessage("操作完成", 3000);
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `explicit ElaStatusBar(QWidget* parent = nullptr)` | 构造函数，自动应用 Fluent 主题样式 |

**注意**:

- 该组件自身只提供构造函数，addWidget、addPermanentWidget、showMessage、clearMessage 等全部接口继承自 QStatusBar。
- ElaWindow 继承自 QMainWindow，可直接调用 `setStatusBar` 挂载。

### ElaDockWidget

Fluent 风格停靠窗口，内置了主题化的自定义标题栏，支持停靠、浮动与主题切换动画，浮动时带圆角与阴影效果。继承自 QDockWidget。

**头文件**: `#include "ElaDockWidget.h"`

**基本用法**:

```cpp
#include "ElaDockWidget.h"

// 以标题构造停靠窗口
ElaDockWidget* logDockWidget = new ElaDockWidget("日志信息", this);

// 设置停靠窗口内容(继承自 QDockWidget)
logDockWidget->setWidget(new QWidget(this));

// 挂载到主窗口右侧停靠区域, 并调整初始宽度
this->addDockWidget(Qt::RightDockWidgetArea, logDockWidget);
this->resizeDocks({logDockWidget}, {200}, Qt::Horizontal);
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `explicit ElaDockWidget(QWidget* parent = nullptr, Qt::WindowFlags flags = Qt::WindowFlags())` | 默认构造函数 |
| `explicit ElaDockWidget(const QString& title, QWidget* parent = nullptr, Qt::WindowFlags flags = Qt::WindowFlags())` | 以窗口标题构造，标题显示在自定义标题栏上 |

**注意**:

- 构造时自动安装 Fluent 风格标题栏(setTitleBarWidget)，不要再手动替换标题栏，否则会丢失主题联动效果。
- setWidget、setAllowedAreas、setFeatures 等接口继承自 QDockWidget；停靠布局由 QMainWindow::addDockWidget 和 resizeDocks 管理。
- Windows 平台上重写了 nativeEvent 以处理浮动窗口的原生窗口效果，其他平台无需额外处理。
- 主题模式切换时标题栏与背景带过渡动画，跟随 ElaTheme 全局主题自动变化。

## 容器与布局

### ElaRibbonBar

Office 风格的 Ribbon 工具栏容器, 由选项卡栏与页面堆栈组成, 支持折叠/展开动画、固定(Pin)、右键固定菜单以及绑定外部标签栏。继承自 QWidget。

**头文件**: `#include "ElaRibbonBar.h"`

**基本用法**:

```cpp
#include "ElaRibbonBar.h"
#include "ElaRibbonGroup.h"

// 创建 Ribbon 工具栏, 默认自带内置选项卡栏
ElaRibbonBar* ribbonBar = new ElaRibbonBar(this);
ribbonBar->setAnimationDuration(500); // 折叠/展开动画时长(毫秒)

// 添加选项卡页, 返回该页的容器 QWidget
QWidget* homePage = ribbonBar->addTab("开始");

// 在页面上添加分组, 分组内添加工具按钮
ElaRibbonGroup* clipGroup = ribbonBar->addGroup(homePage, "剪贴板");
clipGroup->addToolButton(ElaIconType::Paste, "粘贴");
clipGroup->addToolButton(ElaIconType::Copy, "复制");

ElaRibbonGroup* fontGroup = ribbonBar->addGroup(homePage, "字体");
fontGroup->addToolButton(ElaIconType::Bold, "加粗");
fontGroup->addToolButton(ElaIconType::Italic, "斜体");

// 监听选项卡点击与折叠状态变化
connect(ribbonBar, &ElaRibbonBar::tabClicked, this, [=](int index) {
    qDebug() << "点击选项卡" << index;
});
connect(ribbonBar, &ElaRibbonBar::collapsedChanged, this, [=](bool collapsed) {
    qDebug() << "折叠状态" << collapsed;
});
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `QWidget* addTab(const QString& title)` | 添加一个选项卡, 返回该选项卡对应的页面容器 |
| `ElaRibbonGroup* addGroup(QWidget* page, const QString& title)` | 在指定页面上追加一个分组; page 必须是 addTab 返回的页面 |
| `void bindTabBar(ElaRibbonTabBar* tabBar)` | 绑定外部标签栏, 内置标签栏隐藏; 传 nullptr 恢复内置标签栏 |
| `ElaRibbonTabBar* tabBar() const` | 返回当前生效的标签栏(外部优先, 否则内置) |
| `void setCurrentIndex(int currentIndex)` | 切换当前选项卡, 同步页面与标签栏 |
| `int getCurrentIndex() const` | 获取当前选项卡索引 |
| `int tabCount() const` | 选项卡数量 |
| `QString tabText(int index) const` | 指定索引的选项卡标题 |
| `void setCollapsed(bool collapsed)` | 折叠/展开内容区, 带高度动画 |
| `bool isCollapsed() const` | 是否处于折叠状态 |
| `void setPinned(bool pinned)` | 固定 Ribbon, 固定后不再自动折叠 |
| `bool isPinned() const` | 是否已固定 |
| `void setAnimationDuration(int durationMs)` | 折叠动画时长, 默认 200 毫秒 |
| `void showPinContextMenu(const QPoint& globalPos)` | 在指定全局坐标弹出"固定/折叠"右键菜单 |

**信号**:

| 信号 | 说明 |
| --- | --- |
| `void tabClicked(int index)` | 选项卡被点击 |
| `void collapsedChanged(bool collapsed)` | 折叠状态变化 |
| `void pinnedChanged(bool pinned)` | 固定状态变化 |
| `void pCurrentIndexChanged()` | 当前选项卡索引变化(属性信号) |

**注意**:

- 默认未固定(isPinned() 为 false): 鼠标离开 Ribbon 区域约 150 毫秒后自动折叠, 只保留标签栏; 调用 setPinned(true) 或通过右键菜单"固定 Ribbon"可关闭自动折叠。
- 重复点击当前已选中的选项卡会切换折叠状态(对应 ElaRibbonTabBar 的 tabReclicked 信号)。
- 在 Ribbon 区域或标签栏上右键会自动弹出"固定 Ribbon / 折叠 Ribbon"菜单, 无需手动调用 showPinContextMenu。
- bindTabBar 绑定外部标签栏后, ElaRibbonBar 高度固定为 88px, 外部标签栏可放入自定义标题栏区域(示例程序即把它嵌入窗口标题栏); 绑定时会把已有选项卡标题复制到外部标签栏。

### ElaRibbonTabBar

Ribbon 的选项卡栏。ElaRibbonBar 已内置一个, 通常无需单独创建; 当需要把标签栏放到窗口标题栏等 Ribbon 之外的位置时, 可独立实例化后通过 ElaRibbonBar::bindTabBar 绑定。继承自 QWidget。

**头文件**: `#include "ElaRibbonTabBar.h"`

**基本用法**:

```cpp
#include "ElaRibbonBar.h"
#include "ElaRibbonTabBar.h"

// 独立创建标签栏(例如放入自定义标题栏)
ElaRibbonTabBar* tabBar = new ElaRibbonTabBar(this);

// 绑定到 RibbonBar: 内置标签栏隐藏, 由外部标签栏驱动页面切换
ElaRibbonBar* ribbonBar = new ElaRibbonBar(this);
ribbonBar->bindTabBar(tabBar);

// 绑定后照常通过 RibbonBar 添加选项卡, 标题会同步到外部标签栏
QWidget* homePage = ribbonBar->addTab("开始");
QWidget* insertPage = ribbonBar->addTab("插入");

// 也可以直接操作标签栏
connect(tabBar, &ElaRibbonTabBar::tabClicked, this, [=](int index) {
    qDebug() << "点击标签" << tabBar->tabText(index);
});
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `int appendTab(const QString& title)` | 追加一个标签, 返回其索引 |
| `void removeTab(int index)` | 移除指定索引的标签 |
| `void clear()` | 清空全部标签 |
| `int tabCount() const` | 标签数量 |
| `QString tabText(int index) const` | 获取标签标题 |
| `void setTabText(int index, const QString& title)` | 修改标签标题 |
| `void setCurrentIndex(int CurrentIndex)` | 设置当前选中标签 |
| `int getCurrentIndex() const` | 获取当前选中标签索引 |

**信号**:

| 信号 | 说明 |
| --- | --- |
| `void tabClicked(int index)` | 标签被点击 |
| `void tabReclicked(int index)` | 已选中的标签被再次点击(RibbonBar 用它切换折叠) |
| `void pCurrentIndexChanged()` | 当前索引变化(属性信号) |

**注意**:

- 与 ElaRibbonBar 配合使用时, 增删标签应通过 ElaRibbonBar::addTab 完成, 保证标签与页面一一对应; 直接对已绑定的标签栏调用 appendTab/removeTab 会导致标签与页面数量不一致。
- ElaRibbonBar::bindTabBar 绑定时会先调用外部标签栏的 clear() 再复制现有标题, 外部标签栏上原有的标签会被清除。

### ElaRibbonGroup

Ribbon 页面内的分组容器, 内容水平排列, 底部绘制分组标题与两侧分隔线。通常由 ElaRibbonBar::addGroup 创建并自动加入页面布局。继承自 QWidget。

**头文件**: `#include "ElaRibbonGroup.h"`

**基本用法**:

```cpp
#include "ElaRibbonBar.h"
#include "ElaRibbonGroup.h"
#include "ElaCheckBox.h"

QWidget* viewPage = ribbonBar->addTab("视图");

// 添加分组与工具按钮(默认 Large: 52x52, 文字在图标下方)
ElaRibbonGroup* zoomGroup = ribbonBar->addGroup(viewPage, "缩放");
zoomGroup->addToolButton(ElaIconType::Plus, "放大");
zoomGroup->addToolButton(ElaIconType::Minus, "缩小", ElaRibbonGroup::Small);

// 分组内也可以放任意 QWidget
ElaRibbonGroup* prefsGroup = ribbonBar->addGroup(viewPage, "显示设置");
QWidget* checkColumn = new QWidget(this);
QVBoxLayout* checkLayout = new QVBoxLayout(checkColumn);
checkLayout->addWidget(new ElaCheckBox("网格线", this));
checkLayout->addWidget(new ElaCheckBox("标尺", this));
prefsGroup->addWidget(checkColumn);
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `explicit ElaRibbonGroup(const QString& title, QWidget* parent = nullptr)` | 构造分组并指定标题 |
| `void setTitle(const QString& title)` | 设置底部分组标题 |
| `QString getTitle() const` | 获取分组标题 |
| `ElaToolButton* addToolButton(ElaIconType::IconName icon, const QString& text, ButtonSize size = Large)` | 添加工具按钮并返回, 可继续 connect 其 clicked 信号 |
| `void addWidget(QWidget* widget)` | 向分组内容区追加任意控件 |

**注意**:

- ButtonSize 枚举取值为 ElaRibbonGroup::Large 与 ElaRibbonGroup::Small。Large 按钮 52x52, 图标 24x24, 文字显示在图标下方; Small 按钮 30x30, 仅显示图标, 按钮文字仍会设置, 适合作为紧凑排列的图标按钮。
- addToolButton 返回 ElaToolButton 指针, 业务响应通过 connect 该按钮的 clicked 信号实现。

### ElaExpander

可折叠面板, 带有标题/副标题/图标的 header, 点击 header 以动画方式展开或收起内容区域, 支持向下或向上两个展开方向。继承自 QWidget。

**头文件**: `#include "ElaExpander.h"`

**基本用法**:

```cpp
#include "ElaExpander.h"
#include "ElaCheckBox.h"
#include "ElaLineEdit.h"

// 创建折叠面板并配置 header
ElaExpander* expander = new ElaExpander("网络设置", this);
expander->setSubTitle("配置代理和网络参数");
expander->setHeaderIcon(ElaIconType::WifiExclamation);

// 组装内容区域并挂载
QWidget* content = new QWidget(this);
QVBoxLayout* contentLayout = new QVBoxLayout(content);
contentLayout->addWidget(new ElaCheckBox("启用代理", this));
ElaLineEdit* proxyHost = new ElaLineEdit(this);
proxyHost->setPlaceholderText("代理地址 (例如: 127.0.0.1)");
contentLayout->addWidget(proxyHost);
expander->setContentWidget(content);

// 向上展开的面板
ElaExpander* expanderUp = new ElaExpander("高级设置", this);
expanderUp->setExpandDirection(ElaExpander::Up);

// 代码控制展开, 并监听状态变化
expander->setIsExpanded(true);
connect(expander, &ElaExpander::expandStateChanged, this, [=](bool expanded) {
    qDebug() << "展开状态" << expanded;
});
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `explicit ElaExpander(const QString& title, QWidget* parent = nullptr)` | 构造并设置标题 |
| `void setContentWidget(QWidget* widget)` | 设置展开后显示的内容控件 |
| `QWidget* getContentWidget() const` | 获取内容控件 |
| `void setHeaderWidget(QWidget* widget)` | 在 header 内嵌自定义控件(位于左侧图标区之后); 控件会被设置鼠标事件穿透, 仅作展示, 不能交互 |
| `void setIsExpanded(bool expanded)` | 代码控制展开/收起 |
| `bool getIsExpanded() const` | 当前是否展开 |
| `void setExpandDirection(ExpandDirection direction)` | 设置展开方向, ElaExpander::Down(默认) 或 ElaExpander::Up |
| `ExpandDirection getExpandDirection() const` | 获取展开方向 |
| `void setTitle(QString Title)` | 设置标题 |
| `void setSubTitle(QString SubTitle)` | 设置副标题(显示在标题右侧) |
| `void setHeaderIcon(ElaIconType::IconName HeaderIcon)` | 设置 header 左侧图标, 默认 ElaIconType::None |
| `void setAnimationDuration(int AnimationDuration)` | 展开动画时长, 默认 250 毫秒 |
| `void setBorderRadius(int BorderRadius)` | 圆角半径, 默认 6 |

**信号**:

| 信号 | 说明 |
| --- | --- |
| `void expandStateChanged(bool expanded)` | 展开状态变化 |

**注意**:

- 内容控件的高度决定展开后的面板高度, 内容布局建议使用零边距(setContentsMargins(0, 0, 0, 0)), 避免出现多余留白。
- 选择 ElaExpander::Up 方向时面板向上展开, 适合放在页面底部的场景。

### ElaDrawerArea

抽屉容器, 由一个 header 和若干抽屉项组成; 点击 header 或调用 expand()/collapse() 以动画方式展开、收起全部抽屉项。继承自 QWidget。

**头文件**: `#include "ElaDrawerArea.h"`

**基本用法**:

```cpp
#include "ElaDrawerArea.h"
#include "ElaText.h"
#include "ElaCheckBox.h"

ElaDrawerArea* drawer = new ElaDrawerArea(this);

// 自定义 header 内容
QWidget* header = new QWidget(this);
QHBoxLayout* headerLayout = new QHBoxLayout(header);
ElaText* headerText = new ElaText("ElaDrawer", this);
headerText->setTextPixelSize(15);
headerLayout->addWidget(headerText);
headerLayout->addStretch();
drawer->setDrawerHeader(header);

// 添加抽屉项, 每项建议固定高度
QWidget* item1 = new QWidget(this);
item1->setFixedHeight(75);
QHBoxLayout* item1Layout = new QHBoxLayout(item1);
item1Layout->addWidget(new ElaCheckBox("测试窗口1", this));
drawer->addDrawer(item1);

// 代码控制展开/收起, 并监听状态
drawer->expand();
connect(drawer, &ElaDrawerArea::expandStateChanged, this, [=](bool isExpand) {
    qDebug() << "抽屉展开" << isExpand;
});
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `void setDrawerHeader(QWidget* widget)` | 设置 header 区域的内容控件 |
| `void addDrawer(QWidget* widget)` | 追加一个抽屉项 |
| `void removeDrawer(QWidget* widget)` | 移除指定抽屉项 |
| `void expand()` | 展开全部抽屉项 |
| `void collapse()` | 收起全部抽屉项 |
| `bool getIsExpand() const` | 当前是否展开 |
| `void setBorderRadius(int BorderRadius)` | 圆角半径 |
| `void setHeaderHeight(int HeaderHeight)` | header 高度 |

**信号**:

| 信号 | 说明 |
| --- | --- |
| `void expandStateChanged(bool isExpand)` | 展开状态变化(点击 header 或调用 expand/collapse 均会触发) |

**注意**:

- 点击 header 空白区域即可切换展开状态, 无需额外绑定; 点击 header 内嵌的 Ela 控件(如文字、开关)不会触发切换。若用开关(如 ElaToggleSwitch)控制, 应同时监听 expandStateChanged 反向同步开关状态, 避免两者不一致。
- 抽屉项应设置固定高度(示例中为 75px), 展开动画依赖各项高度计算。

### ElaGroupBox

FluentUI 风格的分组框, 在 QGroupBox 基础上绘制圆角边框, 其余行为与 QGroupBox 完全一致, 可直接使用 setTitle、setCheckable 等父类接口。继承自 QGroupBox。

**头文件**: `#include "ElaGroupBox.h"`

**基本用法**:

```cpp
#include "ElaGroupBox.h"
#include "ElaCheckBox.h"
#include "ElaRadioButton.h"

ElaGroupBox* groupBox = new ElaGroupBox("ElaGroupBox", this);
groupBox->setFixedSize(350, 220);

// 与 QGroupBox 相同的用法: 直接设置布局并添加控件
QVBoxLayout* layout = new QVBoxLayout(groupBox);
layout->setContentsMargins(15, 25, 15, 15); // 顶部留出标题空间
layout->addWidget(new ElaCheckBox("GroupBox 内的复选框", groupBox));
layout->addWidget(new ElaRadioButton("选项 1", groupBox));
layout->addWidget(new ElaRadioButton("选项 2", groupBox));
layout->addStretch();
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `explicit ElaGroupBox(QWidget* parent = nullptr)` | 构造无标题分组框 |
| `explicit ElaGroupBox(const QString& title, QWidget* parent = nullptr)` | 构造并设置标题 |
| `void setBorderRadius(int BorderRadius)` | 圆角半径 |
| `int getBorderRadius() const` | 获取圆角半径 |
| `void setTitle(const QString& title)` | 设置标题(继承自 QGroupBox) |
| `void setCheckable(bool checkable)` | 标题带复选框, 可整体启用/禁用内容(继承自 QGroupBox) |

**注意**:

- 内容布局顶部边距建议不小于 25px, 为标题文字留出空间。

### ElaWizard

分步向导弹窗: 顶部绘制步骤指示器(圆形序号 + 连接线 + 步骤标题), 中部为页面区域, 底部内置"取消/上一步/下一步/完成"按钮。继承自 QWidget, 但内部以 Qt::Tool 无边框窗口形式弹出, 固定尺寸 600x450, 构造时自动在主屏幕居中。

**头文件**: `#include "ElaWizard.h"`

**基本用法**:

```cpp
#include "ElaWizard.h"
#include "ElaText.h"
#include "ElaLineEdit.h"

ElaWizard* wizard = new ElaWizard(this);

// 逐步添加向导页
QWidget* page1 = new QWidget();
QVBoxLayout* l1 = new QVBoxLayout(page1);
l1->addWidget(new ElaText("欢迎使用安装向导", 16, page1));
l1->addStretch();
wizard->addStep("欢迎", page1);

QWidget* page2 = new QWidget();
QVBoxLayout* l2 = new QVBoxLayout(page2);
ElaLineEdit* pathEdit = new ElaLineEdit(page2);
pathEdit->setText("/usr/local/ElaWidgetTools");
l2->addWidget(pathEdit);
l2->addStretch();
wizard->addStep("路径", page2);

// 监听完成与取消
connect(wizard, &ElaWizard::finished, this, [=]() {
    qDebug() << "向导完成";
});
connect(wizard, &ElaWizard::cancelled, this, [=]() {
    qDebug() << "向导被取消";
});

// 以独立弹窗形式显示
wizard->show();
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `void addStep(const QString& title, QWidget* page)` | 追加一个步骤及其页面 |
| `void next()` | 前进到下一步 |
| `void previous()` | 返回上一步 |
| `void finish()` | 发出 finished() 信号并隐藏窗口 |
| `int getStepCount() const` | 步骤总数 |
| `int getCurrentStep() const` | 当前步骤索引(从 0 开始) |
| `void setBorderRadius(int BorderRadius)` | 窗口圆角半径, 默认 10 |

**信号**:

| 信号 | 说明 |
| --- | --- |
| `void currentStepChanged(int step)` | 当前步骤变化(next/previous 触发) |
| `void finished()` | 最后一步点击"完成"或调用 finish() |
| `void cancelled()` | 点击内置"取消"按钮 |

**注意**:

- 构造函数的 parent 参数不用于窗口父子关系(内部以 nullptr 父级创建独立 Qt::Tool 窗口), 需要自行管理其生命周期或依赖 Qt 对象树以外的方式释放。
- 底部按钮由组件自绘并自动处理: "下一步"在最后一步自动变为"完成", "上一步"在第一步自动禁用, 无需手动创建按钮。
- setCurrentStep(int) 由属性宏生成, 只更新属性值并发出 pCurrentStepChanged() 信号, 不会切换页面; 切换步骤必须使用 next()/previous()。
- 点击"取消"或"完成"只会 hide() 窗口, 不会销毁对象, 可重复 show(); 但当前步骤不会自动重置回第 0 步。

### ElaFlowLayout

流式布局: 子项按行从左到右排列, 宽度不足时自动换行, 可开启子项重排时的位置过渡动画。继承自 QLayout。

**头文件**: `#include "ElaFlowLayout.h"`

**基本用法**:

```cpp
#include "ElaFlowLayout.h"

// margin = 0, 水平间距 = 5, 垂直间距 = 5; 传 -1 表示使用样式默认值
ElaFlowLayout* flowLayout = new ElaFlowLayout(0, 5, 5);
flowLayout->setContentsMargins(30, 0, 0, 0);
flowLayout->setIsAnimation(true); // 开启子项重排动画

// 与普通布局一样添加控件, 窗口宽度变化时自动换行
flowLayout->addWidget(card1);
flowLayout->addWidget(card2);
flowLayout->addWidget(card3);

QWidget* container = new QWidget(this);
container->setLayout(flowLayout);
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `explicit ElaFlowLayout(QWidget* parent, int margin = -1, int hSpacing = -1, int vSpacing = -1)` | 构造并直接安装到 parent 上 |
| `explicit ElaFlowLayout(int margin = -1, int hSpacing = -1, int vSpacing = -1)` | 构造独立布局, 稍后通过 setLayout/addLayout 使用 |
| `void setIsAnimation(bool isAnimation)` | 开启/关闭子项位置变化动画 |
| `int horizontalSpacing() const` | 水平间距 |
| `int verticalSpacing() const` | 垂直间距 |
| `int count() const` | 子项数量 |
| `QLayoutItem* itemAt(int index) const` | 访问指定子项 |
| `QLayoutItem* takeAt(int index)` | 取出并移除指定子项 |
| `bool hasHeightForWidth() const` | 恒为支持高度随宽度变化 |
| `int heightForWidth(int) const` | 给定宽度下布局所需高度 |

**注意**:

- addWidget 继承自 QLayout 基类, 可直接使用。
- margin/hSpacing/vSpacing 传 -1 时使用当前样式的默认间距。
- 适合卡片墙、标签云等宽度自适应场景; 示例程序首页的 ElaPopularCard 卡片区即使用 ElaFlowLayout 排列。

## 滚动与分页

### ElaScrollArea

Fluent 风格滚动区域, 继承自 QScrollArea。构造时自动将水平与垂直滚动条替换为 ElaScrollBar, 并支持鼠标拖拽滚动手势、越界回弹(OverShoot)与平滑滚动动画, 适合承载卡片流、长内容页面等可滚动内容。

**头文件**: `#include "ElaScrollArea.h"`

**基本用法**:

```cpp
#include <QHBoxLayout>

#include "ElaScrollArea.h"

// 创建滚动区域, 承载横向卡片流
ElaScrollArea* scrollArea = new ElaScrollArea(this);
scrollArea->setWidgetResizable(true);
// 启用鼠标左键拖拽滚动, 按下事件延迟设为 0 秒(立即响应拖动)
scrollArea->setIsGrabGesture(true, 0);
// 启用水平方向越界回弹效果
scrollArea->setIsOverShoot(Qt::Horizontal, true);
// 启用垂直方向滚动条的滚动范围过渡动画
scrollArea->setIsAnimation(Qt::Vertical, true);

// 设置内容部件
QWidget* contentWidget = new QWidget(this);
contentWidget->setStyleSheet("background-color:transparent;");
QHBoxLayout* contentLayout = new QHBoxLayout(contentWidget);
contentLayout->setContentsMargins(30, 0, 0, 6);
scrollArea->setWidget(contentWidget);
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `ElaScrollArea(QWidget* parent = nullptr)` | 构造函数, 自动装配 ElaScrollBar |
| `void setIsGrabGesture(bool isEnable, qreal mousePressEventDelay = 0.5)` | 启用/禁用鼠标左键拖拽滚动手势, 第二参数为鼠标按下事件的派发延迟(秒) |
| `void setIsOverShoot(Qt::Orientation orientation, bool isEnable)` | 启用/禁用指定方向的越界回弹效果 |
| `bool getIsOverShoot(Qt::Orientation orientation) const` | 获取指定方向是否启用越界回弹 |
| `void setIsAnimation(Qt::Orientation orientation, bool isAnimation)` | 启用/禁用指定方向滚动条的滚动范围过渡动画, 转发到内部 ElaScrollBar 的 IsAnimation 属性 |
| `bool getIsAnimation(Qt::Orientation orientation) const` | 获取指定方向滚动条是否启用滚动范围过渡动画 |

**注意**:

- 构造时水平与垂直滚动条策略均被设为 `Qt::ScrollBarAlwaysOff`, 滚轮与手势仍可滚动但滚动条不可见; 需要显示内置滚动条时调用 `setHorizontalScrollBarPolicy` / `setVerticalScrollBarPolicy` 重新设置, 或仿照 ElaScrollPage 的做法用 `ElaScrollBar(QScrollBar*, QAbstractScrollArea*)` 附加悬浮滚动条。
- 启用抓取手势后, 子控件的鼠标按下事件会被延迟 `mousePressEventDelay` 秒派发, 用于区分点击与拖拽滚动; 内容以可交互控件为主时保留默认 0.5, 纯展示内容可传 0。
- `setIsOverShoot` 基于 QScroller 实现, 通常与 `setIsGrabGesture(true)` 搭配使用。

### ElaScrollBar

Fluent 风格滚动条, 继承自 QScrollBar。默认呈细条状, 鼠标悬停约 350 毫秒后自动展开加宽; 滚轮平滑滚动动画始终启用, 滚动范围过渡动画可通过 IsAnimation 属性开启, 并可通过专用构造函数以浮动模式覆盖在任意 QAbstractScrollArea 之上, 接管其原生滚动条。

**头文件**: `#include "ElaScrollBar.h"`

**基本用法**:

```cpp
#include "ElaListView.h"
#include "ElaScrollBar.h"

// 用法一: 独立创建指定方向的滚动条
ElaScrollBar* vScrollBar = new ElaScrollBar(Qt::Vertical, this);
// 启用滚动范围过渡动画
vScrollBar->setIsAnimation(true);

// 用法二: 浮动滚动条, 悬浮于视图之上并接管其原生滚动条
ElaListView* listView = new ElaListView(this);
ElaScrollBar* floatScrollBar = new ElaScrollBar(listView->verticalScrollBar(), listView);
floatScrollBar->setIsAnimation(true);
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `ElaScrollBar(QWidget* parent = nullptr)` | 构造函数 |
| `ElaScrollBar(Qt::Orientation orientation, QWidget* parent = nullptr)` | 构造指定方向的滚动条 |
| `ElaScrollBar(QScrollBar* originScrollBar, QAbstractScrollArea* parent = nullptr)` | 浮动滚动条构造: 绑定并接管 originScrollBar, 悬浮于 parent 之上, 两者数值双向同步 |
| `void setIsAnimation(bool IsAnimation)` | 设置是否启用滚动范围过渡动画, 默认 false; 滚轮平滑滚动始终启用, 不受该属性控制 |
| `bool getIsAnimation() const` | 获取是否启用滚动范围过渡动画 |
| `void setSpeedLimit(qreal SpeedLimit)` | 设置滚轮连续滚动时平滑动画的累计距离上限系数, 默认 20 |
| `qreal getSpeedLimit() const` | 获取滚动速度上限系数 |

**信号**:

- `void rangeAnimationFinished()`: 滚动范围过渡动画结束时发出(仅在启用 IsAnimation、滚动条可见且新范围最大值非 0 时触发)。

**注意**:

- 浮动构造函数要求 originScrollBar 与 parent 均非空, 否则输出错误日志并退化为普通滚动条; 构造时会自动将 parent 对应方向的原生滚动条策略设为 `Qt::ScrollBarAlwaysOff`。
- ElaScrollArea、ElaScrollPage、ElaVirtualList 等组件内部已自带 ElaScrollBar, 无需重复替换; 浮动模式主要用于 ElaListView、ElaTableView、ElaTreeView 等视图类组件。

### ElaScrollPage

标准滚动页面容器, 继承自 QWidget。顶部为面包屑标题栏(ElaBreadcrumbBar), 中部为可堆叠的多个内容页; 每个通过 addCentralWidget 添加的部件都会被自动包裹进 ElaScrollArea 并附加浮动滚动条, 支持页内多级导航与路由回退, 是编写 ElaWindow 各页面的推荐基类。

**头文件**: `#include "ElaScrollPage.h"`

**基本用法**:

```cpp
#include <QVBoxLayout>

#include "ElaScrollPage.h"
#include "ElaText.h"

// 页面通常以继承 ElaScrollPage 的方式编写, 以下代码位于页面构造函数中

// 主内容页: windowTitle 将作为面包屑导航名称
QWidget* centralWidget = new QWidget(this);
centralWidget->setWindowTitle("首页");
QVBoxLayout* layout = new QVBoxLayout(centralWidget);
layout->addWidget(new ElaText("页面内容", 15, this));
layout->addStretch();
// 添加主内容页: 自动包裹 ElaScrollArea 并附加浮动滚动条
addCentralWidget(centralWidget, true, true, 0);

// 二级页面: 添加后通过 navigation 切换
QWidget* subWidget = new QWidget(this);
subWidget->setWindowTitle("详情页");
addCentralWidget(subWidget);

// 在按钮点击等时机调用 navigation 切换到索引 1 的页面
// 面包屑自动追加 "详情页", 点击面包屑可返回上级
// navigation(1);
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `ElaScrollPage(QWidget* parent = nullptr)` | 构造函数 |
| `void addCentralWidget(QWidget* centralWidget, bool isWidgetResizeable = true, bool isVerticalGrabGesture = true, qreal mousePressEventDelay = 0.5)` | 添加一个内容页, 自动包裹 ElaScrollArea; 参数依次控制内容自适应、垂直拖拽手势、按下事件延迟 |
| `void setPageTitle(const QString& title)` | 修改面包屑首项标题(即页面主标题) |
| `void navigation(int widgetIndex, bool isLogRoute = true)` | 切换到指定索引的内容页; isLogRoute 为 true 时记录到 ElaNavigationRouter 路由栈 |
| `void setTitleVisible(bool isVisible)` | 设置面包屑标题栏是否可见 |
| `void setPageTitleSpacing(int spacing)` | 设置标题栏左侧留白间距 |
| `int getPageTitleSpacing() const` | 获取标题栏左侧留白间距(当前版本 `setPageTitleSpacing` 未同步该值, 恒返回初始值 0) |
| `void setCustomWidget(QWidget* CustomWidget)` | 在标题栏与内容区之间插入自定义部件(常用于副标题、工具按钮行) |
| `QWidget* getCustomWidget() const` | 获取自定义部件 |

**注意**:

- 内容页以 windowTitle 作为注册名: 调用 `addCentralWidget` 之前先 `setWindowTitle`, 未设置时自动命名为 `Page_N`; 面包屑导航与 `navigation` 均依赖该名称。
- `setPageTitle` 的实现是重命名面包屑首项, 必须在首次 `addCentralWidget` 之后调用才生效。
- 内容以视图类组件(如 ElaListView)为主的页面, 建议 `addCentralWidget(centralWidget, true, false, 0)` 关闭垂直拖拽手势, 避免与视图自身的选择/拖拽操作冲突(示例工程均采用此写法)。
- 页面首页(如 T_Home)不需要面包屑时可调用 `setTitleVisible(false)`。

### ElaScrollPageArea

圆角卡片容器, 继承自 QWidget。按当前主题绘制圆角背景与边框, 默认固定高度 75 像素, 常用于 ElaScrollPage 内容区中将一组控件包装为一行卡片, 是示例工程中组织页面内容的基本单元。

**头文件**: `#include "ElaScrollPageArea.h"`

**基本用法**:

```cpp
#include <QHBoxLayout>

#include "ElaScrollPageArea.h"
#include "ElaText.h"
#include "ElaToggleSwitch.h"

// 创建一行卡片, 左侧为说明文字, 右侧为开关
ElaScrollPageArea* switchArea = new ElaScrollPageArea(this);
// 调整圆角半径, 默认 6
switchArea->setBorderRadius(8);
QHBoxLayout* switchLayout = new QHBoxLayout(switchArea);
switchLayout->addWidget(new ElaText("ElaToggleSwitch", 15, this));
switchLayout->addStretch();
switchLayout->addWidget(new ElaToggleSwitch(this));
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `ElaScrollPageArea(QWidget* parent = nullptr)` | 构造函数, 默认固定高度 75 像素 |
| `void setBorderRadius(int BorderRadius)` | 设置圆角半径, 默认 6 |
| `int getBorderRadius() const` | 获取圆角半径 |

**注意**:

- 构造时调用了 `setFixedHeight(75)`, 放置多行内容(如内嵌列表、分割器)时需要手动调用 `setFixedHeight` 调整高度。
- 背景与边框颜色随 ElaTheme 主题切换自动变化, 无需手动处理。

### ElaSplitter

Fluent 风格分割器, 继承自 QSplitter。手柄中央绘制圆角抓握条(grip), 悬停与按压时有主题色反馈; 支持水平与垂直方向, 默认禁止子部件折叠。用法与 QSplitter 一致, 通过 addWidget / setSizes 管理面板。

**头文件**: `#include "ElaSplitter.h"`

**基本用法**:

```cpp
#include <QVBoxLayout>

#include "ElaSplitter.h"
#include "ElaText.h"

// 创建水平分割器, 左右两个面板
ElaSplitter* splitter = new ElaSplitter(Qt::Horizontal, this);
splitter->setFixedHeight(200);

QWidget* leftPanel = new QWidget(this);
leftPanel->setMinimumWidth(120);
QVBoxLayout* leftLayout = new QVBoxLayout(leftPanel);
leftLayout->addWidget(new ElaText("左侧面板", 14, this));
leftLayout->addStretch();

QWidget* rightPanel = new QWidget(this);
rightPanel->setMinimumWidth(120);
QVBoxLayout* rightLayout = new QVBoxLayout(rightPanel);
rightLayout->addWidget(new ElaText("拖拽中间手柄调整面板大小", 13, this));
rightLayout->addStretch();

splitter->addWidget(leftPanel);
splitter->addWidget(rightPanel);
// 设置初始尺寸比例
splitter->setSizes({300, 300});
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `ElaSplitter(QWidget* parent = nullptr)` | 构造函数, 默认水平方向 |
| `ElaSplitter(Qt::Orientation orientation, QWidget* parent = nullptr)` | 构造指定方向的分割器 |
| `void setHandleWidth(int HandleWidth)` | 设置手柄宽度并同步更新实际分割条宽度, 默认 6 |
| `int getHandleWidth() const` | 获取手柄宽度 |
| `void setGripLength(int GripLength)` | 设置手柄中央抓握条的长度, 默认 36 |
| `int getGripLength() const` | 获取抓握条长度 |

**注意**:

- 构造时调用了 `setChildrenCollapsible(false)`, 子部件不会被拖拽折叠到 0 宽度; 需要折叠行为时自行调用 `setChildrenCollapsible(true)`。
- `setGripLength` 只影响之后新建的手柄, 必须在 `addWidget` 之前调用才生效。
- 面板尺寸变化可通过基类信号 `QSplitter::splitterMoved(int pos, int index)` 监听。

### ElaPagination

分页导航控件, 继承自 QWidget。由上一页/下一页箭头按钮、页码按钮、省略号快进快退按钮和可选的跳页输入框组成, 页码过多时自动折叠为省略号, 适合表格、列表等数据的分页展示。

**头文件**: `#include "ElaPagination.h"`

**基本用法**:

```cpp
#include <QStackedWidget>

#include "ElaPagination.h"

QStackedWidget* pageStack = new QStackedWidget(this);
// ... 向 pageStack 添加各页内容

// 创建分页控件: 共 50 页, 当前第 1 页, 显示跳页输入框
ElaPagination* pagination = new ElaPagination(this);
pagination->setTotalPages(50);
pagination->setCurrentPage(1);
pagination->setJumperVisible(true);

// 用户切换页码时刷新内容
connect(pagination, &ElaPagination::currentPageChanged, this, [=](int page) {
    pageStack->setCurrentIndex(page - 1);
});
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `ElaPagination(QWidget* parent = nullptr)` | 构造函数 |
| `void setCurrentPage(int CurrentPage)` | 设置当前页码, 默认 1 |
| `int getCurrentPage() const` | 获取当前页码 |
| `void setTotalPages(int TotalPages)` | 设置总页数, 默认 1 |
| `int getTotalPages() const` | 获取总页数 |
| `void setButtonSize(int ButtonSize)` | 设置页码按钮边长(像素), 默认 28 |
| `int getButtonSize() const` | 获取页码按钮边长 |
| `void setPagerCount(int PagerCount)` | 设置页码按钮最多显示个数, 超出折叠为省略号, 默认 11 |
| `int getPagerCount() const` | 获取页码按钮最多显示个数 |
| `void setJumperVisible(bool JumperVisible)` | 设置是否显示跳页输入框, 默认 false |
| `bool getJumperVisible() const` | 获取跳页输入框是否可见 |

**信号**:

- `void currentPageChanged(int page)`: 用户点击页码/箭头/省略号, 或在跳页输入框回车确认时发出, 携带新页码。

**注意**:

- 程序化调用 `setCurrentPage` 只发出属性变更信号 `pCurrentPageChanged()`, 不发出 `currentPageChanged(int)`; 代码切页后需自行同步关联界面。
- 点击省略号按钮一次快进/快退 `PagerCount - 2` 页。
- 跳页输入框在按回车且输入页码合法(1 到 TotalPages 之间且不等于当前页)时生效; 无论是否生效, 回车后输入框都会自动清空。

### ElaVirtualList

面向大数据量的虚拟化列表视图, 继承自 QListView。构造时启用 uniformItemSizes、Batched 分批布局与按像素平滑滚动, 并自带 ElaScrollBar, 配合任意 QAbstractItemModel 可流畅展示万级条目。

**头文件**: `#include "ElaVirtualList.h"`

**基本用法**:

```cpp
#include <QStandardItemModel>

#include "ElaVirtualList.h"

// 创建虚拟列表并填充 10000 条数据
ElaVirtualList* virtualList = new ElaVirtualList(this);
QStandardItemModel* model = new QStandardItemModel(this);
for (int i = 0; i < 10000; ++i)
{
    model->appendRow(new QStandardItem(QString("虚拟列表项 #%1").arg(i + 1)));
}
virtualList->setModel(model);

// 关闭背景透明, 使用主题底色
virtualList->setIsTransparent(false);
// 启用隔行变色
virtualList->setIsAlternatingRowColors(true);
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `ElaVirtualList(QWidget* parent = nullptr)` | 构造函数, 自动配置虚拟化滚动与 ElaScrollBar |
| `void setItemHeight(int ItemHeight)` | 设置条目高度属性值, 默认 40(见下方注意) |
| `int getItemHeight() const` | 获取条目高度 |
| `void setIsTransparent(bool IsTransparent)` | 设置背景是否透明, 默认 true; 为 false 时以主题底色填充 |
| `bool getIsTransparent() const` | 获取背景是否透明 |
| `void setIsAlternatingRowColors(bool IsAlternatingRowColors)` | 设置隔行变色, 默认 false; 奇数行以主题交替色填充背景 |
| `bool getIsAlternatingRowColors() const` | 获取隔行变色是否启用 |
| `void setItemCount(int count)` | 设置条目总数; 未调用 `setModel` 时同步内置占位模型的行数, 数据经 `itemRequestData` 按需填充 |
| `int getItemCount() const` | 获取设置的条目总数 |

**信号**:

- `void itemRequestData(int startIndex, int endIndex)`: 懒加载数据请求信号; 可见行范围变化(滚动、窗口尺寸变化或调用 `setItemCount`)时发出, 携带当前可见的首末行号, 同一范围不会重复发出。

**注意**:

- 两种数据提供方式: 常规方式用 `setModel` 挂接任意 QAbstractItemModel; 懒加载方式不调用 `setModel`, 用 `setItemCount(n)` 声明总行数(组件构造时已内置一个 QStandardItemModel 占位模型承载行数), 再监听 `itemRequestData`, 在槽中通过 `model()->setData` 填充可见范围的数据。
- 已调用 `setModel` 挂接外部模型后, `setItemCount` 不再改动模型行数, 仅记录计数; `itemRequestData` 信号仍会随滚动发出, 可用于外部模型的分批取数。
- `ItemHeight` 在构造时应用到内部样式, 运行期调用 `setItemHeight` 仅更新属性值, 不会刷新已生效的条目高度。
- 视图默认启用 `setUniformItemSizes(true)`, 要求所有条目等高, 这是虚拟化性能的前提, 不要为单个条目设置不同高度。

## 对话框与浮层

### ElaContentDialog

模态内容对话框, 弹出时在父窗口上叠加遮罩, 底部内置左/中/右三个按钮, 常用于退出确认等需要用户抉择的场景。继承自 QDialog, 默认 Qt::ApplicationModal。

**头文件**: `#include "ElaContentDialog.h"`

**基本用法**:

```cpp
// 拦截主窗口关闭事件, 弹出退出确认对话框
ElaContentDialog* closeDialog = new ElaContentDialog(this);
// 默认中心内容为"退出/确定要退出程序吗", 可自定义按钮文本
closeDialog->setLeftButtonText("取消");
closeDialog->setMiddleButtonText("最小化");
closeDialog->setRightButtonText("退出");
// 不需要的按钮可以隐藏
// closeDialog->setMiddleButtonVisible(false);

// 右键按钮确认退出, 中间按钮改为最小化
connect(closeDialog, &ElaContentDialog::rightButtonClicked, this, &MainWindow::close);
connect(closeDialog, &ElaContentDialog::middleButtonClicked, this, [=]() {
    closeDialog->close();
    showMinimized();
});

// 配合 ElaWindow: 关闭默认关闭行为, 点击关闭按钮时改为弹出对话框
this->setIsDefaultClosed(false);
connect(this, &MainWindow::closeButtonClicked, this, [=]() {
    closeDialog->exec();
});

// 替换中心内容区域
QWidget* central = new QWidget(this);
// ... 在 central 中布置自定义内容 ...
closeDialog->setCentralWidget(central);
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `explicit ElaContentDialog(QWidget* parent)` | 构造函数, parent 不可为空, 遮罩依附于父窗口 |
| `void setCentralWidget(QWidget* centralWidget)` | 替换按钮栏上方的中心内容区域 |
| `void setLeftButtonText(QString text)` | 设置左按钮文本, 默认 "cancel" |
| `void setMiddleButtonText(QString text)` | 设置中间按钮文本, 默认 "minimum" |
| `void setRightButtonText(QString text)` | 设置右按钮文本, 默认 "exit", 主题色高亮 |
| `void setLeftButtonVisible(bool visible)` | 设置左按钮是否可见 |
| `void setMiddleButtonVisible(bool visible)` | 设置中间按钮是否可见 |
| `void setRightButtonVisible(bool visible)` | 设置右按钮是否可见 |
| `void close()` | 以关闭动画收起对话框 |

**信号**:

| 信号 | 说明 |
| --- | --- |
| `void leftButtonClicked()` | 左按钮被点击, 点击后对话框自动收起 |
| `void middleButtonClicked()` | 中间按钮被点击, 对话框不会自动关闭 |
| `void rightButtonClicked()` | 右按钮被点击, 点击后对话框自动收起 |

**注意**:

- 构造函数要求非空 parent, 遮罩尺寸取自父窗口, 不能作为独立顶层窗口使用。
- 左/右按钮点击后自动播放关闭动画; 中间按钮不会自动关闭, 需要在槽中自行调用 `close()`。
- `onLeftButtonClicked()` / `onMiddleButtonClicked()` / `onRightButtonClicked()` 是虚槽函数, 子类可重写以在按钮点击时插入逻辑。

### ElaDialog

Fluent 风格无边框对话框窗口, 自带 ElaAppBar 标题栏(置顶/最小化/最大化/关闭按钮), 背景色跟随主题, 适合承载自定义对话框界面。继承自 QDialog。

**头文件**: `#include "ElaDialog.h"`

**基本用法**:

```cpp
// 创建对话框, 默认尺寸 500x500
ElaDialog* dialog = new ElaDialog(this);
dialog->setWindowTitle("设置");

// 只保留关闭按钮, 并固定窗口大小
dialog->setWindowButtonFlags(ElaAppBarType::CloseButtonHint);
dialog->setIsFixedSize(true);

// 移动到屏幕中心后模态显示
dialog->moveToCenter();
dialog->exec();

// 拦截关闭: 点击关闭按钮不直接关闭, 由业务代码决定
dialog->setIsDefaultClosed(false);
connect(dialog, &ElaDialog::closeButtonClicked, dialog, [=]() {
    // ... 自行校验后调用 dialog->close() ...
});
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `explicit ElaDialog(QWidget* parent = nullptr)` | 构造函数, 默认尺寸 500x500 |
| `void moveToCenter()` | 移动到当前屏幕可用区域中心 |
| `void setWindowButtonFlags(ElaAppBarType::ButtonFlags buttonFlags)` | 设置标题栏按钮组合, 默认 StayTop, Minimize, Maximize, Close |
| `void setWindowButtonFlag(ElaAppBarType::ButtonType buttonFlag, bool isEnable = true)` | 单独启用或禁用某个标题栏按钮 |
| `ElaAppBarType::ButtonFlags getWindowButtonFlags() const` | 获取当前标题栏按钮组合 |
| `void setIsStayTop(bool isStayTop)` | 设置窗口是否置顶, 默认 true |
| `void setIsFixedSize(bool isFixedSize)` | 设置窗口是否固定大小 |
| `void setIsDefaultClosed(bool isDefaultClosed)` | 为 false 时点击关闭按钮不关闭窗口, 仅发出 closeButtonClicked |
| `void setAppBarHeight(int appBarHeight)` | 设置标题栏高度 |
| `int getAppBarHeight() const` | 获取标题栏高度 |

**信号**:

| 信号 | 说明 |
| --- | --- |
| `void closeButtonClicked()` | 标题栏关闭按钮被点击, 配合 setIsDefaultClosed(false) 可拦截关闭 |
| `void routeBackButtonClicked()` | 标题栏路由返回按钮被点击 |
| `void navigationButtonClicked()` | 标题栏导航按钮被点击 |
| `void themeChangeButtonClicked()` | 标题栏主题切换按钮被点击 |

**注意**:

- 标题栏按钮枚举在 ElaDef.h 的 `ElaAppBarType::ButtonType` 中, 可用 `|` 组合, 例如 `ElaAppBarType::MinimizeButtonHint | ElaAppBarType::CloseButtonHint`。
- 构造时默认开启置顶(IsStayTop 为 true), 不需要时调用 `setIsStayTop(false)`。

### ElaMessageDialog

轻量消息确认面板, 显示标题与正文, 底部内置确认/取消两个按钮, 适合简短的二次确认提示。继承自 QWidget, 需要自行设置窗口标志并定位显示。

**头文件**: `#include "ElaMessageDialog.h"`

**基本用法**:

```cpp
// 创建消息对话框并配置内容
ElaMessageDialog* messageDialog = new ElaMessageDialog(this);
messageDialog->setTitle("删除确认");
messageDialog->setContent("确定要删除这条记录吗?");
messageDialog->setFixedSize(280, 150);
// 作为弹出层显示: 需要手动设置窗口标志与透明背景
messageDialog->setWindowFlags(Qt::Popup | Qt::FramelessWindowHint);
messageDialog->setAttribute(Qt::WA_TranslucentBackground);

// 根据信号判断用户点击了哪个按钮
connect(messageDialog, &ElaMessageDialog::confirmed, this, [=]() {
    qDebug() << "确认按钮被点击";
});
connect(messageDialog, &ElaMessageDialog::cancelled, this, [=]() {
    qDebug() << "取消按钮被点击";
});

// 在按钮下方弹出
connect(button, &ElaPushButton::clicked, this, [=]() {
    QPoint globalPos = button->mapToGlobal(QPoint(0, button->height() + 5));
    messageDialog->move(globalPos);
    messageDialog->show();
});
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `explicit ElaMessageDialog(QWidget* parent = nullptr)` | 构造函数, 最小尺寸 280x150 |
| `void setTitle(QString Title)` | 设置标题文本, 默认 "标题" |
| `QString getTitle() const` | 获取标题文本 |
| `void setContent(QString Content)` | 设置正文文本 |
| `void setTitlePixelSize(int TitlePixelSize)` | 设置标题字号, 默认 15 |
| `void setContentPixelSize(int ContentPixelSize)` | 设置正文字号, 默认 13 |
| `void setBorderRadius(int BorderRadius)` | 设置圆角半径, 默认 8 |

**信号**:

| 信号 | 说明 |
| --- | --- |
| `void confirmed()` | 确认按钮被点击, 点击后自动 hide() |
| `void cancelled()` | 取消按钮被点击, 点击后自动 hide() |

**注意**:

- 该组件继承自 QWidget 而非 QDialog, 没有 exec() 模态循环; 弹出层用法需自行设置 `Qt::Popup | Qt::FramelessWindowHint` 与 `Qt::WA_TranslucentBackground`, 并用 `move()` 定位后 `show()`。
- 确认/取消按钮文本内置, 头文件未提供修改按钮文本的接口; 需要自定义按钮文本时改用 ElaPopconfirm 或 ElaContentDialog。

### ElaInputDialog

Fluent 风格输入对话框, 支持单行文本、整数、小数与多行文本输入, 提供与 QInputDialog 类似的静态便捷函数。继承自 QDialog。

**头文件**: `#include "ElaInputDialog.h"`

**基本用法**:

```cpp
// 静态函数: 获取单行文本
bool ok = false;
QString text = ElaInputDialog::getText(this, "输入对话框", "请输入您的信息", "名称:", "", &ok);
if (ok && !text.isEmpty())
{
    qDebug() << "文本输入:" << text;
}

// 静态函数: 获取整数(初值 18, 范围 0-150, 步长 1)
int age = ElaInputDialog::getInt(this, "输入年龄", "请提供您的个人信息", "年龄:", 18, 0, 150, 1, &ok);

// 静态函数: 获取小数(初值 99.99, 范围 0.0-9999.99, 保留 2 位小数)
double price = ElaInputDialog::getDouble(this, "输入价格", "商品定价系统", "价格:", 99.99, 0.0, 9999.99, 2, &ok);

// 静态函数: 获取多行文本
QString note = ElaInputDialog::getMultiLineText(this, "输入备注", "请详细描述您的需求", "详细描述:", "", &ok);

// 实例用法: 密码输入
ElaInputDialog* inputDialog = new ElaInputDialog(this);
inputDialog->setTitleText("登录");
inputDialog->setLabelText("密码:");
inputDialog->setTextEchoMode(QLineEdit::Password);
if (inputDialog->exec() == QDialog::Accepted)
{
    qDebug() << inputDialog->getTextValue();
}
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `static QString getText(QWidget* parent, const QString& title, const QString& subtitle, const QString& label, const QString& text = QString(), bool* ok = nullptr, ...)` | 模态获取单行文本, ok 返回用户是否点击确定 |
| `static int getInt(QWidget* parent, const QString& title, const QString& subtitle, const QString& label, int value = 0, int minValue = -2147483647, int maxValue = 2147483647, int step = 1, bool* ok = nullptr, ...)` | 模态获取整数 |
| `static double getDouble(QWidget* parent, const QString& title, const QString& subtitle, const QString& label, double value = 0.0, double minValue = -2147483647.0, double maxValue = 2147483647.0, int decimals = 2, bool* ok = nullptr, ...)` | 模态获取小数 |
| `static QString getMultiLineText(QWidget* parent, const QString& title, const QString& subtitle, const QString& label, const QString& text = QString(), bool* ok = nullptr, ...)` | 模态获取多行文本 |
| `void setTitleText(QString TitleText)` | 设置对话框标题文本 |
| `void setSubTitleText(QString SubTitleText)` | 设置副标题文本 |
| `void setLabelText(QString LabelText)` | 设置输入框前的标签文本 |
| `void setTextValue(QString TextValue)` | 设置文本输入初值 |
| `QString getTextValue() const` | 获取当前文本值 |
| `void setPlaceholderText(QString PlaceholderText)` | 设置输入框占位文本 |
| `void setOkButtonText(QString OkButtonText)` | 设置确定按钮文本, 默认 "确定" |
| `void setCancelButtonText(QString CancelButtonText)` | 设置取消按钮文本, 默认 "取消" |
| `void setTextEchoMode(QLineEdit::EchoMode mode)` | 设置回显模式, 如 QLineEdit::Password |
| `void setIntRange(int minValue, int maxValue, int step = 1)` | 切换为整数输入模式并设置范围与步长 |
| `void setDoubleRange(double minValue, double maxValue, int decimals = 2)` | 切换为小数输入模式并设置范围与小数位数 |
| `void setMultiLine(bool multiLine)` | 切换单行/多行文本输入 |

**信号**:

| 信号 | 说明 |
| --- | --- |
| `void textValueChanged(QString text)` | 文本值变化 |
| `void intValueChanged(int value)` | 整数值变化 |
| `void doubleValueChanged(double value)` | 小数值变化 |

**注意**:

- 静态函数省略的尾部参数为 `okButtonText = "确定"`, `cancelButtonText = "取消"`, `inputMinWidth = 100`, `inputMaxWidth = QWIDGETSIZE_MAX`, 一般无需传入。
- 静态函数返回值在用户取消时不可直接使用, 必须通过 ok 参数判断。

### ElaColorDialog

Fluent 风格颜色选择对话框, 支持取色、RGB 显示与自定义颜色列表, 是 QColorDialog 的替代品。继承自 QDialog。

**头文件**: `#include "ElaColorDialog.h"`

**基本用法**:

```cpp
// 创建颜色对话框
ElaColorDialog* colorDialog = new ElaColorDialog(this);
// 设置初始颜色
colorDialog->setCurrentColor(QColor(0x0E, 0x6F, 0xC3));

// 点击按钮弹出取色
connect(pickButton, &ElaPushButton::clicked, this, [=]() {
    colorDialog->exec();
});

// 用户确认选色后处理结果
connect(colorDialog, &ElaColorDialog::colorSelected, this, [=](const QColor& color) {
    qDebug() << "选中颜色:" << color << colorDialog->getCurrentColorRGB();
});
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `explicit ElaColorDialog(QWidget* parent = nullptr)` | 构造函数 |
| `void setCurrentColor(QColor CurrentColor)` | 设置当前颜色 |
| `QColor getCurrentColor() const` | 获取当前颜色 |
| `QString getCurrentColorRGB() const` | 获取当前颜色的 RGB 字符串表示 |
| `QList<QColor> getCustomColorList() const` | 获取自定义颜色列表 |
| `QColor getCustomColor(int index) const` | 获取指定序号的自定义颜色 |

**信号**:

| 信号 | 说明 |
| --- | --- |
| `void colorSelected(const QColor& color)` | 用户确认选择颜色 |
| `void pCurrentColorChanged()` | 当前颜色属性变化 |

### ElaSheetPanel

半模态滑出面板(Sheet), 从窗口底部或左右两侧滑出, 支持 Peek/Half/Full 三档高度、拖拽调整与遮罩点击关闭, 适合移动端风格的详情、表单浮层。继承自 QWidget。

**头文件**: `#include "ElaSheetPanel.h"`

**基本用法**:

```cpp
// 父对象传顶层窗口, 面板覆盖在窗口内容之上
ElaSheetPanel* sheetPanel = new ElaSheetPanel(window());
sheetPanel->setDragHandleVisible(true);     // 显示顶部拖拽手柄
sheetPanel->setCloseOnOverlayClick(true);   // 点击遮罩关闭

// 设置面板内容
QWidget* content = new QWidget();
QVBoxLayout* layout = new QVBoxLayout(content);
layout->addWidget(new ElaText("Sheet 面板内容", 16, content));
layout->addStretch();
sheetPanel->setCentralWidget(content);

// 以不同档位打开
sheetPanel->open(ElaSheetPanelType::Peek);  // 低档, 默认高度比 0.15
sheetPanel->open(ElaSheetPanelType::Half);  // 半屏, 默认 0.50
sheetPanel->open(ElaSheetPanelType::Full);  // 接近全屏, 默认 0.85

// 监听档位变化与关闭
connect(sheetPanel, &ElaSheetPanel::detentChanged, this, [=](ElaSheetPanelType::DetentLevel level) {
    qDebug() << "当前档位:" << level;
});
connect(sheetPanel, &ElaSheetPanel::closed, this, [=]() {
    qDebug() << "面板已关闭";
});
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `explicit ElaSheetPanel(QWidget* parent = nullptr)` | 构造函数, parent 建议传顶层窗口 |
| `void setCentralWidget(QWidget* widget)` | 设置面板内容控件 |
| `void open(ElaSheetPanelType::DetentLevel level = ElaSheetPanelType::Half)` | 以指定档位打开面板, 档位有 Peek/Half/Full |
| `void close()` | 关闭面板 |
| `ElaSheetPanelType::DetentLevel currentDetent() const` | 获取当前档位 |
| `bool isOpened() const` | 面板是否处于打开状态 |
| `void setDirection(ElaSheetPanelType::Direction Direction)` | 设置滑出方向, Bottom/Left/Right, 默认 Bottom |
| `void setPeekRatio(qreal PeekRatio)` | 设置 Peek 档位占窗口的比例, 默认 0.15 |
| `void setHalfRatio(qreal HalfRatio)` | 设置 Half 档位比例, 默认 0.50 |
| `void setFullRatio(qreal FullRatio)` | 设置 Full 档位比例, 默认 0.85 |
| `void setDragHandleVisible(bool DragHandleVisible)` | 设置拖拽手柄是否可见, 默认 true |
| `void setCloseOnOverlayClick(bool CloseOnOverlayClick)` | 设置点击遮罩是否关闭, 默认 true |
| `void setOverlayOpacity(qreal OverlayOpacity)` | 设置遮罩不透明度, 默认 0.4 |

**信号**:

| 信号 | 说明 |
| --- | --- |
| `void opened()` | 面板打开 |
| `void closed()` | 面板关闭 |
| `void detentChanged(ElaSheetPanelType::DetentLevel level)` | 档位变化(拖拽或调用 open 切换) |

**注意**:

- 构造时 parent 应传 `window()` 这类顶层窗口, 面板与遮罩才能覆盖整个窗口区域; 在页面构造函数中 `window()` 尚未就绪时, 可延迟到首次使用时再创建(示例工程即采用该做法)。
- Direction 与 DetentLevel 枚举定义在 ElaDef.h 的 `ElaSheetPanelType` 中。

### ElaFlyout

轻量级弹出浮层(Flyout), 锚定在目标控件旁弹出, 默认点击外部自动关闭, 可显示标题加正文, 也可承载任意自定义控件。继承自 QWidget。

**头文件**: `#include "ElaFlyout.h"`

**基本用法**:

```cpp
// 文本内容的 Flyout
ElaFlyout* flyout = new ElaFlyout(this);
flyout->setTitle("提示");
flyout->setContent("轻量级弹出面板, 点击外部自动关闭。");

ElaPushButton* flyoutBtn = new ElaPushButton("显示 Flyout", this);
connect(flyoutBtn, &ElaPushButton::clicked, this, [=]() {
    flyout->showFlyout(flyoutBtn); // 锚定在按钮旁弹出
});

// 自定义内容的 Flyout
ElaFlyout* customFlyout = new ElaFlyout(this);
QWidget* customContent = new QWidget();
QVBoxLayout* customLayout = new QVBoxLayout(customContent);
customLayout->setContentsMargins(0, 0, 0, 0);
customLayout->addWidget(new ElaText("请为本次体验评分:", 13, customContent));
customLayout->addWidget(new ElaRatingControl(customContent));
customFlyout->setContentWidget(customContent);
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `explicit ElaFlyout(QWidget* parent = nullptr)` | 构造函数 |
| `void setTitle(QString Title)` | 设置标题文本 |
| `void setContent(QString Content)` | 设置正文文本 |
| `void setContentWidget(QWidget* widget)` | 设置自定义内容控件, 替代标题/正文 |
| `void showFlyout(QWidget* target)` | 锚定在目标控件旁弹出 |
| `void closeFlyout()` | 关闭浮层 |
| `void setIsLightDismiss(bool IsLightDismiss)` | 点击浮层外部是否自动关闭, 默认 true |
| `void setBorderRadius(int BorderRadius)` | 设置圆角半径 |

**信号**:

| 信号 | 说明 |
| --- | --- |
| `void closed()` | 浮层关闭 |

### ElaPopconfirm

气泡确认框, 锚定在目标控件旁弹出带图标的确认/取消气泡, 用于删除等危险操作的就地二次确认, 比模态对话框更轻量。继承自 QWidget。

**头文件**: `#include "ElaPopconfirm.h"`

**基本用法**:

```cpp
// 创建气泡确认框
ElaPopconfirm* popconfirm = new ElaPopconfirm(this);
popconfirm->setTitle("确认删除");
popconfirm->setContent("删除后将无法恢复, 是否继续?");
// 自定义按钮文本与图标
popconfirm->setConfirmButtonText("删除");
popconfirm->setCancelButtonText("再想想");
popconfirm->setIcon(ElaIconType::TrashCan);

// 点击按钮时在其旁边弹出
ElaPushButton* deleteBtn = new ElaPushButton("删除项目", this);
connect(deleteBtn, &ElaPushButton::clicked, this, [=]() {
    popconfirm->showPopconfirm(deleteBtn);
});

// 处理用户选择
connect(popconfirm, &ElaPopconfirm::confirmed, this, [=]() {
    qDebug() << "已确认删除";
});
connect(popconfirm, &ElaPopconfirm::cancelled, this, [=]() {
    qDebug() << "已取消";
});
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `explicit ElaPopconfirm(QWidget* parent = nullptr)` | 构造函数 |
| `void setTitle(QString Title)` | 设置标题文本 |
| `void setContent(QString Content)` | 设置正文文本 |
| `void setConfirmButtonText(QString ConfirmButtonText)` | 设置确认按钮文本 |
| `void setCancelButtonText(QString CancelButtonText)` | 设置取消按钮文本 |
| `void setIcon(ElaIconType::IconName Icon)` | 设置气泡图标, 枚举见 ElaDef.h 的 ElaIconType |
| `void showPopconfirm(QWidget* target)` | 锚定在目标控件旁弹出 |
| `void closePopconfirm()` | 关闭气泡 |
| `void setIsLightDismiss(bool IsLightDismiss)` | 点击气泡外部是否自动关闭, 默认 true |

**信号**:

| 信号 | 说明 |
| --- | --- |
| `void confirmed()` | 确认按钮被点击 |
| `void cancelled()` | 取消按钮被点击 |
| `void closed()` | 气泡关闭(含点击外部关闭) |

### ElaTeachingTip

教学提示气泡(TeachingTip), 带箭头指向目标控件, 支持标题、副标题、正文、图标、配图与自定义操作按钮, 用于功能引导和新特性介绍。继承自 QWidget。

**头文件**: `#include "ElaTeachingTip.h"`

**基本用法**:

```cpp
// 创建教学提示
ElaTeachingTip* teachingTip = new ElaTeachingTip(this);
teachingTip->setTitle("截图功能升级");
teachingTip->setSubTitle("版本 2.0");
teachingTip->setContent("现在支持区域截图、延时截图和 OCR 文字识别。");
teachingTip->setTipIcon(ElaIconType::CameraRetro);
// 箭头方向: Auto/Top/Bottom/Left/Right
teachingTip->setTailPosition(ElaTeachingTip::Bottom);

// 添加操作按钮(带回调)
teachingTip->addAction("跳过", [=]() { teachingTip->closeTip(); });
teachingTip->addAction("了解更多", [=]() { teachingTip->closeTip(); });

// 绑定目标控件并显示
ElaPushButton* targetBtn = new ElaPushButton("显示 TeachingTip", this);
teachingTip->setTarget(targetBtn);
connect(targetBtn, &ElaPushButton::clicked, this, [=]() {
    teachingTip->showTip();
});
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `explicit ElaTeachingTip(QWidget* parent = nullptr)` | 构造函数 |
| `void setTitle(QString Title)` | 设置标题文本 |
| `void setSubTitle(QString SubTitle)` | 设置副标题文本 |
| `void setContent(QString Content)` | 设置正文文本 |
| `void setTipIcon(ElaIconType::IconName TipIcon)` | 设置提示图标 |
| `void setHeroImage(QPixmap HeroImage)` | 设置顶部配图 |
| `void setTailPosition(TailPosition position)` | 设置箭头方向, 枚举 Auto/Top/Bottom/Left/Right |
| `void setTarget(QWidget* target)` | 绑定箭头指向的目标控件 |
| `void setCloseButtonVisible(bool visible)` | 设置右上角关闭按钮是否可见 |
| `void addAction(const QString& text, const std::function<void()>& callback)` | 添加底部操作按钮及点击回调 |
| `void clearActions()` | 清空所有操作按钮 |
| `void showTip()` | 显示提示气泡 |
| `void closeTip()` | 关闭提示气泡 |
| `void setIsLightDismiss(bool IsLightDismiss)` | 点击气泡外部是否自动关闭, 默认 true |

**信号**:

| 信号 | 说明 |
| --- | --- |
| `void closed()` | 气泡关闭 |
| `void closeButtonClicked()` | 右上角关闭按钮被点击 |

**注意**:

- TailPosition 为 Auto 时根据目标控件在窗口中的位置自动选择箭头方向。
- 调用 `showTip()` 前必须先 `setTarget()` 绑定目标控件, 否则气泡无锚定位置。

### ElaToolTip

Fluent 风格工具提示, 挂载到任意控件上替代原生 QToolTip, 支持显示延时、隐藏延时、自动消失时长与自定义内容控件。继承自 QWidget。

**头文件**: `#include "ElaToolTip.h"`

**基本用法**:

```cpp
// 挂载到目标控件: 构造时把目标控件作为 parent 传入即可
ElaToolTip* cardToolTip = new ElaToolTip(urlCard);
cardToolTip->setToolTip("https://github.com/RainbowCandyX/ElaWidgetTools");

// 悬停 500ms 后显示, 3 秒后自动消失
cardToolTip->setShowDelayMsec(500);
cardToolTip->setDisplayMsec(3000);

// 使用自定义控件作为提示内容
ElaToolTip* richToolTip = new ElaToolTip(someWidget);
QWidget* custom = new QWidget();
// ... 在 custom 中布置任意内容 ...
richToolTip->setCustomWidget(custom);
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `explicit ElaToolTip(QWidget* parent = nullptr)` | 构造函数, parent 即挂载目标, 悬停其上时显示提示 |
| `void setToolTip(QString ToolTip)` | 设置提示文本 |
| `void setDisplayMsec(int DisplayMsec)` | 设置显示后自动隐藏的时长(毫秒), 默认 -1 表示不自动隐藏 |
| `void setShowDelayMsec(int ShowDelayMsec)` | 设置悬停后延迟显示的时长(毫秒), 默认 0 |
| `void setHideDelayMsec(int HideDelayMsec)` | 设置移出后延迟隐藏的时长(毫秒), 默认 0 |
| `void setCustomWidget(QWidget* CustomWidget)` | 设置自定义提示内容控件, 替代纯文本 |
| `void setBorderRadius(int BorderRadius)` | 设置圆角半径, 默认 5 |
| `void updatePos()` | 手动刷新提示位置 |

**注意**:

- 挂载方式与其他组件不同: 目标控件通过构造函数的 parent 参数传入, 组件内部对其安装事件过滤器监听悬停, 没有单独的 setTarget 接口。
- 不要与 QWidget::setToolTip() 混用, 否则原生提示与 ElaToolTip 会同时出现。

## 消息与通知

本章介绍 ElaWidgetTools 中用于消息提示、通知管理与引导展示的 8 个组件: ElaMessageBar, ElaMessageButton, ElaInfoBar, ElaToast, ElaSnackbar, ElaNotificationCenter, ElaSpotlight, ElaSplashScreen。

### ElaMessageBar

带标题与正文的消息条, 从窗口指定方位滑入, 到时自动消失, 适合操作结果反馈(成功/警告/信息/错误)。继承自 QWidget, 构造函数私有, 只能通过四个静态方法弹出。

**头文件**: `#include "ElaMessageBar.h"`

**基本用法**:

```cpp
#include "ElaMessageBar.h"

// 以下代码位于某 QWidget 成员函数中, this 为当前窗口

// 在窗口右上角弹出成功消息, 显示 2000 毫秒
ElaMessageBar::success(ElaMessageBarType::TopRight, "Success", "文件保存成功", 2000, this);

// 在窗口顶部居中弹出信息消息
ElaMessageBar::information(ElaMessageBarType::Top, "提示", "配置已更新", 1500, this);

// 不传 parent 时自动查找应用内的 ElaWindow 主窗口作为父窗口
ElaMessageBar::warning(ElaMessageBarType::BottomLeft, "Warning", "磁盘空间不足", 3000);
ElaMessageBar::error(ElaMessageBarType::BottomRight, "Error", "网络连接失败", 3000);
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `static void success(ElaMessageBarType::PositionPolicy policy, QString title, QString text, int displayMsec, QWidget* parent = nullptr)` | 弹出成功消息条 |
| `static void warning(ElaMessageBarType::PositionPolicy policy, QString title, QString text, int displayMsec, QWidget* parent = nullptr)` | 弹出警告消息条 |
| `static void information(ElaMessageBarType::PositionPolicy policy, QString title, QString text, int displayMsec, QWidget* parent = nullptr)` | 弹出信息消息条 |
| `static void error(ElaMessageBarType::PositionPolicy policy, QString title, QString text, int displayMsec, QWidget* parent = nullptr)` | 弹出错误消息条 |

**注意**:

- `ElaMessageBarType::PositionPolicy` 取值: `Top`, `Left`, `Bottom`, `Right`, `TopRight`, `TopLeft`, `BottomRight`, `BottomLeft`, 定义在 ElaDef.h 中。
- `displayMsec` 没有默认值, 必须显式传入。
- `parent` 传 `nullptr` 时, 内部会遍历顶层窗口查找 ElaWindow 实例作为父窗口; 如果应用中不存在 ElaWindow(例如主窗口是普通 QMainWindow), 消息条不会显示, 此时必须显式传入父窗口。
- 消息条显示在父窗口内部并跟随父窗口缩放重新定位, 到时后自动销毁, 无需手动释放。

### ElaMessageButton

点击后自动弹出 ElaMessageBar 的按钮, 将消息条的标题、正文、类型、位置预先配置在按钮上, 适合演示或固定提示场景。继承自 QPushButton。

**头文件**: `#include "ElaMessageButton.h"`

**基本用法**:

```cpp
#include "ElaMessageButton.h"

// 默认配置: Success 类型, TopRight 位置, 显示 2000 毫秒
ElaMessageButton* successButton = new ElaMessageButton("Success", this);
successButton->setBarTitle("Success");
successButton->setBarText("操作已成功完成");

// 自定义消息类型与弹出位置
ElaMessageButton* warningButton = new ElaMessageButton("Warning", this);
warningButton->setBarTitle("Warning");
warningButton->setBarText("请先保存当前修改");
warningButton->setMessageMode(ElaMessageBarType::Warning);
warningButton->setPositionPolicy(ElaMessageBarType::BottomLeft);
warningButton->setDisplayMsec(3000);
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `explicit ElaMessageButton(QString text, QWidget* parent = nullptr)` | 以按钮文字构造 |
| `void setBarTitle(QString barTitle)` | 设置弹出消息条的标题 |
| `void setBarText(QString barText)` | 设置弹出消息条的正文 |
| `void setMessageMode(ElaMessageBarType::MessageMode messageMode)` | 设置消息类型, 默认 `Success` |
| `void setPositionPolicy(ElaMessageBarType::PositionPolicy positionPolicy)` | 设置弹出位置, 默认 `TopRight` |
| `void setDisplayMsec(int displayMsec)` | 设置显示时长, 默认 2000 毫秒 |
| `void setMessageTargetWidget(QWidget* messageTargetWidget)` | 设置消息条弹出的目标窗口 |
| `void setBorderRadius(int borderRadius)` | 设置按钮圆角半径 |

**注意**:

- `ElaMessageBarType::MessageMode` 取值: `Success`, `Warning`, `Information`, `Error`。
- `MessageTargetWidget` 默认 `nullptr`, 此时消息条弹在自动查找到的 ElaWindow 上; 非 ElaWindow 应用需要调用 `setMessageTargetWidget` 显式指定目标窗口。

### ElaInfoBar

内嵌式信息栏, 作为普通控件放进布局长期展示, 带彩色侧条、图标、可选关闭按钮和行内操作按钮, 适合页面内的状态说明(许可证到期、连接失败等)。继承自 QFrame。

**头文件**: `#include "ElaInfoBar.h"`

**基本用法**:

```cpp
#include "ElaInfoBar.h"

// 信息级别的提示栏
ElaInfoBar* infoBar = new ElaInfoBar(ElaInfoBarType::Informational, this);
infoBar->setTitle("提示");
infoBar->setMessage("这是一条信息提示, 用于展示一般性的通知内容。");
layout->addWidget(infoBar);

// 警告级别, 附带两个操作按钮
ElaInfoBar* warningBar = new ElaInfoBar(ElaInfoBarType::Warning, this);
warningBar->setTitle("警告");
warningBar->setMessage("你的许可证将在 7 天后过期。");
warningBar->addAction("续费", [=]() { qDebug() << "续费按钮被点击"; });
warningBar->addAction("稍后提醒", [=]() { qDebug() << "稍后提醒按钮被点击"; });
layout->addWidget(warningBar);

// 错误级别, 禁用关闭按钮, 强制用户处理
ElaInfoBar* errorBar = new ElaInfoBar(ElaInfoBarType::Error, this);
errorBar->setTitle("错误");
errorBar->setMessage("无法连接到服务器, 请检查网络设置。");
errorBar->setIsClosable(false);
errorBar->addAction("重试", [=]() { qDebug() << "重试按钮被点击"; });
layout->addWidget(errorBar);
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `explicit ElaInfoBar(ElaInfoBarType::InfoBarSeverity severity, QWidget* parent = nullptr)` | 以严重级别构造 |
| `void setTitle(QString title)` | 设置标题 |
| `void setMessage(QString message)` | 设置正文 |
| `void setSeverity(ElaInfoBarType::InfoBarSeverity severity)` | 设置严重级别, 默认 `Informational` |
| `void setIsClosable(bool isClosable)` | 是否显示关闭按钮, 默认 `true` |
| `void setInfoBarIcon(ElaIconType::IconName infoBarIcon)` | 自定义图标, 默认 `ElaIconType::None` 时按级别取内置图标 |
| `void addAction(const QString& text, const std::function<void()>& callback)` | 添加行内操作按钮及回调 |
| `void clearActions()` | 移除全部操作按钮 |
| `void closeInfoBar()` | 以代码方式关闭信息栏 |
| `void setBorderRadius(int borderRadius)` | 设置圆角半径, 默认 4 |

**信号**:

- `void closed()`: 信息栏关闭完成时发出。
- `void closeButtonClicked()`: 用户点击关闭按钮时发出。

**注意**:

- `ElaInfoBarType::InfoBarSeverity` 取值: `Informational`, `Success`, `Warning`, `Error`。
- ElaInfoBar 是嵌入布局的常驻控件, 不会自动消失; 需要临时弹出提示时应改用 ElaMessageBar 或 ElaToast。

### ElaToast

轻量级气泡提示, 在窗口顶部居中淡入淡出, 只有一行文字和类型图标, 适合无需打断用户的简短反馈。继承自 QWidget, 构造函数私有, 只能通过静态方法弹出。

**头文件**: `#include "ElaToast.h"`

**基本用法**:

```cpp
#include "ElaToast.h"

// 以下代码位于某 QWidget 成员函数中

// 在顶层窗口顶部居中弹出提示, 默认显示 2000 毫秒
ElaToast::success("操作成功完成!", 2000, window());
ElaToast::info("这是一条提示信息", 2000, window());
ElaToast::warning("请注意检查输入", 2000, window());
ElaToast::error("操作失败, 请重试", 2000, window());

// 不传 parent 时显示在主屏幕顶部居中
ElaToast::info("全局提示");
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `static void success(const QString& text, int displayMsec = 2000, QWidget* parent = nullptr)` | 弹出成功提示 |
| `static void info(const QString& text, int displayMsec = 2000, QWidget* parent = nullptr)` | 弹出信息提示 |
| `static void warning(const QString& text, int displayMsec = 2000, QWidget* parent = nullptr)` | 弹出警告提示 |
| `static void error(const QString& text, int displayMsec = 2000, QWidget* parent = nullptr)` | 弹出错误提示 |

**注意**:

- 传入 `parent` 时, Toast 显示在该窗口区域顶部居中(顶部向下 60 像素); 不传时显示在主屏幕顶部居中。位置在弹出时一次性计算, 不随窗口移动更新; 示例工程中统一传 `window()`。
- Toast 显示结束后自动销毁, 静态方法无返回值, 无法在弹出后修改内容。

### ElaSnackbar

底部居中弹出的操作条, 支持一个行内操作按钮(如"撤销"、"重试"), 多条同时弹出时自动向上堆叠, 适合可撤销操作或需要跟进动作的提示。继承自 QWidget, 构造函数私有, 通过静态方法弹出并返回实例指针。

**头文件**: `#include "ElaSnackbar.h"`

**基本用法**:

```cpp
#include "ElaSnackbar.h"
#include "ElaToast.h"

// 以下代码位于某 QWidget 成员函数中

// 纯文本提示, 无操作按钮
ElaSnackbar::success("文件保存成功!", "", 3000, window());

// 带"撤销"按钮, 通过返回的指针连接 actionClicked 信号
ElaSnackbar* snackbar = ElaSnackbar::info("已删除 3 个项目", "撤销", 5000, window());
connect(snackbar, &ElaSnackbar::actionClicked, this, [=]() {
    ElaToast::success("已撤销删除操作", 2000, window());
});

// 限制同屏最多显示 3 条, 超出时最早的一条被挤出
ElaSnackbar::setMaxCount(3);
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `static ElaSnackbar* success(const QString& text, const QString& actionText = "", int displayMsec = 4000, QWidget* parent = nullptr)` | 弹出成功操作条, 返回实例指针 |
| `static ElaSnackbar* info(const QString& text, const QString& actionText = "", int displayMsec = 4000, QWidget* parent = nullptr)` | 弹出信息操作条 |
| `static ElaSnackbar* warning(const QString& text, const QString& actionText = "", int displayMsec = 4000, QWidget* parent = nullptr)` | 弹出警告操作条 |
| `static ElaSnackbar* error(const QString& text, const QString& actionText = "", int displayMsec = 4000, QWidget* parent = nullptr)` | 弹出错误操作条 |
| `void dismiss()` | 立即关闭该操作条 |
| `static void setMaxCount(int count)` | 设置同屏最大条数, 默认 5, 有效范围 1 到 12 |
| `static int getMaxCount()` | 获取同屏最大条数 |

**信号**:

- `void actionClicked()`: 用户点击行内操作按钮时发出。
- `void closed()`: 操作条关闭时发出。

**注意**:

- `actionText` 传空字符串时不显示操作按钮。
- 传入 `parent` 时显示在该窗口底部居中(距底 30 像素), 不传时显示在主屏幕底部居中。
- 超过最大条数时最早弹出的一条自动 dismiss, 其余条目重新排列。
- 返回的指针只应在弹出后立即用于 connect, 操作条到时会自动销毁, 不要长期持有该指针。

### ElaNotificationCenter

从锚点窗口右侧滑入的通知中心面板, 集中管理带标题、内容、时间戳和图标的通知列表, 适合应用级消息汇总入口。继承自 QWidget, 自身是无边框独立面板窗口。

**头文件**: `#include "ElaNotificationCenter.h"`

**基本用法**:

```cpp
#include "ElaNotificationCenter.h"

// 创建通知中心并预置通知, 新通知插入在最前
ElaNotificationCenter* notificationCenter = new ElaNotificationCenter(this);
notificationCenter->addNotification({"系统更新", "ElaWidgetTools 已更新到 v2.1", "10:30"});
notificationCenter->addNotification({"构建完成", "项目编译成功, 耗时 12 秒", "10:25", ElaIconType::Check});
notificationCenter->addNotification({"新消息", "收到来自 Qt 社区的新回复", "09:45", ElaIconType::Envelope});

// 点击按钮切换面板显示与隐藏, 锚点通常传主窗口
connect(button, &ElaPushButton::clicked, this, [=]() {
    if (notificationCenter->isPanelVisible())
    {
        notificationCenter->hidePanel();
    }
    else
    {
        notificationCenter->showPanel(window());
    }
});

// 点击某条通知
connect(notificationCenter, &ElaNotificationCenter::notificationClicked, this, [=](int index) {
    qDebug() << "点击了第" << index << "条通知";
});
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `explicit ElaNotificationCenter(QWidget* parent = nullptr)` | 构造通知中心 |
| `void addNotification(const NotificationItem& item)` | 添加一条通知, 新通知排在最前 |
| `void clearAll()` | 清空全部通知 |
| `int getNotificationCount() const` | 获取当前通知条数 |
| `void showPanel(QWidget* anchor)` | 从锚点窗口右侧滑入面板, 面板高度与锚点一致 |
| `void hidePanel()` | 滑出并隐藏面板 |
| `bool isPanelVisible() const` | 面板是否可见 |
| `void setPanelWidth(int panelWidth)` | 设置面板宽度, 默认 360 |
| `void setBorderRadius(int borderRadius)` | 设置圆角半径, 默认 8 |

**信号**:

- `void notificationClicked(int index)`: 用户点击某条通知时发出, `index` 为列表索引。
- `void panelVisibilityChanged(bool visible)`: 面板显示状态变化时发出。

**注意**:

- `NotificationItem` 结构体字段: `QString title`, `QString content`, `QString timestamp`, `ElaIconType::IconName icon`(默认 `ElaIconType::None`), 支持花括号列表初始化。
- `showPanel` 的锚点通常传 `window()`, 面板贴着锚点右边缘向左滑入并占满锚点高度; 面板是 `Qt::Tool` 独立窗口, 不会嵌入锚点布局。

### ElaSpotlight

聚光灯引导层, 在父窗口上覆盖半透明遮罩并高亮指定控件, 配合标题与说明文字实现单点提示或多步骤新手引导。继承自 QWidget。

**头文件**: `#include "ElaSpotlight.h"`

**基本用法**:

```cpp
#include "ElaSpotlight.h"

// 以顶层窗口为父窗口创建, 遮罩覆盖整个窗口
ElaSpotlight* spotlight = new ElaSpotlight(window());

// 单目标聚光: 先设置标题与说明, 再高亮目标控件
spotlight->setTitle("启动屏按钮");
spotlight->setContent("点击此按钮可以展示启动屏效果。");
spotlight->showSpotlight(targetButton, "我知道了");

// 多步骤引导: 依次高亮多个控件
QList<ElaSpotlight::SpotlightStep> steps;
steps.append({buttonA, "启动屏", "展示应用启动画面效果", false});
steps.append({buttonB, "底部面板", "从底部滑出半模态面板", false});
steps.append({buttonC, "聚光灯", "高亮任意目标区域", true}); // 最后一步使用圆形高亮
spotlight->setSteps(steps);
spotlight->start();

// 引导结束
connect(spotlight, &ElaSpotlight::finished, this, [=]() {
    qDebug() << "引导完成";
});
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `explicit ElaSpotlight(QWidget* parent = nullptr)` | 构造聚光灯, 父窗口即遮罩覆盖范围 |
| `void showSpotlight(QWidget* target, const QString& buttonText = "知道了")` | 单目标高亮, 使用当前 Title/Content 属性 |
| `void setSteps(const QList<SpotlightStep>& steps)` | 设置多步骤引导序列 |
| `void start()` | 从第一步开始多步骤引导 |
| `void next()` | 跳到下一步 |
| `void previous()` | 回到上一步 |
| `void finish()` | 结束引导并隐藏遮罩 |
| `int currentStep() const` | 当前步骤索引 |
| `int stepCount() const` | 步骤总数 |
| `void setTitle(QString title)` | 设置单目标模式的标题 |
| `void setContent(QString content)` | 设置单目标模式的说明文字 |
| `void setIsCircle(bool isCircle)` | 高亮区域是否使用圆形, 默认 `false`(圆角矩形) |
| `void setPadding(int padding)` | 高亮区域相对目标控件的外扩边距, 默认 8 |
| `void setOverlayAlpha(int overlayAlpha)` | 遮罩不透明度(0 到 255), 默认 120 |

**信号**:

- `void stepChanged(int step)`: 多步骤引导切换步骤时发出。
- `void finished()`: 引导结束时发出。

**注意**:

- `SpotlightStep` 结构体字段: `QWidget* target`, `QString title`, `QString content`, `bool isCircle`, 支持花括号列表初始化。
- 构造时应传入顶层窗口(如 `window()`)作为父窗口, 否则遮罩只覆盖局部区域。
- 单目标模式(`showSpotlight`)与多步骤模式(`setSteps` + `start`)使用同一个实例即可, 无需分别创建。

### ElaSplashScreen

应用启动屏, 独立无边框窗口, 支持 Logo、标题、副标题、状态文字以及进度条或进度环, 加载完成后可平滑过渡到主窗口。继承自 QWidget。

**头文件**: `#include "ElaSplashScreen.h"`

**基本用法**:

```cpp
#include "ElaSplashScreen.h"

// 创建启动屏并配置文案
ElaSplashScreen* splash = new ElaSplashScreen(QPixmap(":/Resource/Image/logo.png"));
splash->setTitle("ElaWidgetTools");
splash->setSubTitle("FluentUI 风格 Qt 组件库");
splash->setStatusText("正在初始化...");
splash->setIsShowProgressBar(false); // 隐藏默认进度条
splash->setIsShowProgressRing(true); // 显示忙碌旋转的进度环
splash->show();

// 加载过程中更新进度与状态文字, 进度范围默认 0 到 100
splash->setValue(30);
splash->setStatusText("正在加载组件...");
splash->setValue(100);

// 加载完成: 启动屏淡出后自动显示并激活主窗口
splash->finish(mainWindow);
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `explicit ElaSplashScreen(const QPixmap& logo, QWidget* parent = nullptr)` | 以 Logo 图片构造 |
| `void setLogo(const QPixmap& logo)` | 设置 Logo 图片 |
| `void setTitle(const QString& title)` | 设置主标题 |
| `void setSubTitle(const QString& subTitle)` | 设置副标题 |
| `void setStatusText(const QString& text)` | 设置底部状态文字 |
| `void setValue(int value)` | 设置当前进度值 |
| `void setMinimum(int minimum)` | 设置进度最小值, 默认 0 |
| `void setMaximum(int maximum)` | 设置进度最大值, 默认 100 |
| `void setIsShowProgressBar(bool isShowProgressBar)` | 是否显示进度条, 默认 `true` |
| `void setIsShowProgressRing(bool isShowProgressRing)` | 是否显示进度环, 默认 `false` |
| `void setIsClosable(bool isClosable)` | 是否允许用户关闭, 默认 `false` |
| `void show()` | 显示启动屏 |
| `void close()` | 关闭启动屏 |
| `void finish(QWidget* mainWindow)` | 淡出启动屏, 完成后显示、置顶并激活主窗口 |

**信号**:

- `void closed()`: 启动屏关闭时发出。

**注意**:

- ElaSplashScreen 始终作为独立顶层窗口显示, 构造函数的 `parent` 不影响其窗口层级。
- `finish(mainWindow)` 内部执行 300 毫秒淡出动画, 动画结束后自动调用 `mainWindow->show()` 并激活主窗口, 无需再手动 show 主窗口; `mainWindow` 传 `nullptr` 时该调用不做任何事。
- 进度条与进度环相互独立, 开启进度环不会自动隐藏进度条, 需要同时调用 `setIsShowProgressBar(false)`; 进度环固定为忙碌旋转动画, 具体进度数值由进度条展示。

## 视图与模型

本章组件均为 Qt Model/View 框架中标准视图类的 FluentUI 风格封装, 完全兼容 QAbstractItemModel 及其派生模型 (QStringListModel, QStandardItemModel, 自定义模型等)。所有视图默认内置 ElaScrollBar 滚动条 (其中 ElaListView / ElaTableView / ElaTableWidget 同时启用逐像素滚动), 也可按需外挂浮动滚动条。

### ElaListView

FluentUI 风格的列表视图, 提供圆角选中高亮与悬停效果, 适用于展示一维列表数据。继承自 QListView, setModel、clicked 等 Model/View 接口照常可用。

**头文件**: `#include "ElaListView.h"`

**基本用法**:

```cpp
#include <QStringListModel>
#include <QWidget>

#include "ElaListView.h"
#include "ElaScrollBar.h"

void createListView(QWidget* parent)
{
    // 创建列表视图并绑定模型, 任意 QAbstractItemModel 均可
    ElaListView* listView = new ElaListView(parent);
    QStringList data;
    data << "夜航星" << "玫瑰少年" << "黑暗森林" << "LAST STARDUST";
    listView->setModel(new QStringListModel(data, parent));

    // 调整每项高度, 默认 35
    listView->setItemHeight(40);

    // 可选: 外挂浮动滚动条, 悬停时才展开
    ElaScrollBar* floatScrollBar = new ElaScrollBar(listView->verticalScrollBar(), listView);
    floatScrollBar->setIsAnimation(true);

    // 点击项的响应
    QObject::connect(listView, &ElaListView::clicked, parent, [=](const QModelIndex& index) {
        // 处理点击的 index
    });
}
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `explicit ElaListView(QWidget* parent = nullptr)` | 构造列表视图 |
| `void setItemHeight(int ItemHeight)` | 设置每项的固定高度, 默认 35, 传入值须大于 0 否则忽略 |
| `int getItemHeight() const` | 获取每项高度 |
| `void setIsTransparent(bool IsTransparent)` | 设置背景是否透明, 默认 false |
| `bool getIsTransparent() const` | 获取背景是否透明 |
| `void setModel(QAbstractItemModel* model)` | 绑定数据模型, 继承自 QListView |
| `void setAlternatingRowColors(bool enable)` | 开启隔行变色, 继承自 QAbstractItemView |

**信号**:

- `void clicked(const QModelIndex& index)`: 继承自 QAbstractItemView, 点击项时发出。

**注意**:

- 构造函数内部已将水平与垂直滚动条替换为 ElaScrollBar 并设置逐像素滚动, 无需重复配置。
- 项高度由内部 style 统一接管, 通过 `setItemHeight` 修改, delegate 的 sizeHint 不生效。

### ElaTableView

FluentUI 风格的表格视图, 默认隐藏网格线, 在整行选择模式下提供整行悬停高亮, 适用于以自定义模型驱动的大数据量表格。继承自 QTableView。

**头文件**: `#include "ElaTableView.h"`

**基本用法**:

```cpp
#include <QHeaderView>
#include <QStandardItemModel>
#include <QWidget>

#include "ElaTableView.h"

void createTableView(QWidget* parent)
{
    ElaTableView* tableView = new ElaTableView(parent);

    // 绑定模型, 实际项目中多为自定义 QAbstractTableModel
    QStandardItemModel* model = new QStandardItemModel(parent);
    model->setHorizontalHeaderLabels(QStringList() << "歌名" << "歌手" << "专辑" << "时长");
    model->appendRow(QList<QStandardItem*>()
                     << new QStandardItem("夜航星") << new QStandardItem("不才")
                     << new QStandardItem("我的三体之章北海传") << new QStandardItem("05:03"));
    tableView->setModel(model);

    // 常见表格配置: 整行选择 + 隔行变色 + 隐藏行号
    tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableView->setAlternatingRowColors(true);
    tableView->verticalHeader()->setHidden(true);
    tableView->verticalHeader()->setMinimumSectionSize(46);
    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);

    // 列宽在视图显示后设置才可靠, 利用 tableViewShow 信号
    QObject::connect(tableView, &ElaTableView::tableViewShow, parent, [=]() {
        tableView->setColumnWidth(0, 205);
        tableView->setColumnWidth(1, 170);
        tableView->setColumnWidth(2, 150);
        tableView->setColumnWidth(3, 60);
    });
}
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `explicit ElaTableView(QWidget* parent = nullptr)` | 构造表格视图 |
| `void setHeaderMargin(int HeaderMargin)` | 设置表头文字边距, 默认 6, 传入负值忽略 |
| `int getHeaderMargin() const` | 获取表头文字边距 |
| `void setModel(QAbstractItemModel* model)` | 绑定数据模型, 继承自 QTableView |
| `void setSelectionBehavior(QAbstractItemView::SelectionBehavior behavior)` | 选择行为, 传入 `QAbstractItemView::SelectRows` 可启用整行悬停高亮, 继承自 QAbstractItemView |
| `void setAlternatingRowColors(bool enable)` | 开启隔行变色, 继承自 QAbstractItemView |
| `QHeaderView* horizontalHeader() const` / `QHeaderView* verticalHeader() const` | 访问表头以设置字体、列宽模式等, 继承自 QTableView |
| `void setColumnWidth(int column, int width)` | 设置列宽, 继承自 QTableView |
| `void setIconSize(const QSize& size)` | 设置单元格图标尺寸, 继承自 QAbstractItemView |

**信号**:

- `void tableViewShow()`: 视图显示 (showEvent) 时发出, 适合在此设置列宽等依赖布局的操作。
- `void tableViewHide()`: 视图隐藏 (hideEvent) 时发出。
- `void clicked(const QModelIndex& index)` / `void doubleClicked(const QModelIndex& index)`: 继承自 QAbstractItemView。

**注意**:

- 构造时已执行 `setShowGrid(false)`, 如需网格线自行调用 `setShowGrid(true)`。
- 整行悬停高亮仅在 `setSelectionBehavior(QAbstractItemView::SelectRows)` 时生效。
- 组件没有 ItemHeight 属性, 行高通过 `verticalHeader()->setMinimumSectionSize()` 或 `setDefaultSectionSize()` 控制。
- 视图显示前直接调用 `setColumnWidth` 可能被后续布局覆盖, 官方示例的做法是在 `tableViewShow` 信号槽中设置列宽。

### ElaTableWidget

FluentUI 风格的便捷表格部件, 内置默认模型, 通过 QTableWidgetItem 直接读写单元格而无需自定义模型, 并额外提供批量行列插删与整行读写的便捷接口, 适用于中小数据量的快速开发。继承自 QTableWidget。

**头文件**: `#include "ElaTableWidget.h"`

**基本用法**:

```cpp
#include <QHeaderView>
#include <QTableWidgetItem>
#include <QWidget>

#include "ElaTableWidget.h"

void createTableWidget(QWidget* parent)
{
    ElaTableWidget* tableWidget = new ElaTableWidget(parent);

    // 设置行列数与表头
    tableWidget->setColumnCount(4);
    tableWidget->setRowCount(2);
    tableWidget->setHorizontalHeaderLabels(QStringList() << "歌名" << "歌手" << "专辑" << "时长");
    tableWidget->verticalHeader()->setHidden(true);
    tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableWidget->setAlternatingRowColors(true);

    // 方式一: 便捷接口整行写入
    tableWidget->setRowData(0, QStringList() << "夜航星" << "不才" << "我的三体之章北海传" << "05:03");

    // 方式二: 标准 QTableWidgetItem 写入, 可控制对齐、颜色等
    QTableWidgetItem* item = new QTableWidgetItem("玫瑰少年");
    item->setTextAlignment(Qt::AlignCenter);
    tableWidget->setItem(1, 0, item);
    tableWidget->setItemText(1, 1, "五月天");

    // 动态插入 2 行并读取整行数据
    tableWidget->insertRows(2, 2);
    QStringList firstRow = tableWidget->getRowData(0);

    // 列宽在视图显示后设置
    QObject::connect(tableWidget, &ElaTableWidget::tableWidgetShow, parent, [=]() {
        tableWidget->setColumnWidth(0, 205);
        tableWidget->setColumnWidth(1, 170);
    });
}
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `explicit ElaTableWidget(QWidget* parent = nullptr)` | 构造表格部件 |
| `void insertRows(int row, int count)` | 从 row 位置起插入 count 行, 参数非法时静默忽略 |
| `void removeRows(int row, int count)` | 从 row 位置起删除 count 行, 超出范围时按实际行数截断 |
| `void insertColumns(int column, int count)` | 从 column 位置起插入 count 列 |
| `void removeColumns(int column, int count)` | 从 column 位置起删除 count 列 |
| `void setItemText(int row, int column, const QString& text)` | 设置单元格文本, 单元格不存在时自动创建 QTableWidgetItem |
| `QString getItemText(int row, int column) const` | 获取单元格文本, 越界或空单元格返回空字符串 |
| `void setRowData(int row, const QStringList& data)` | 整行写入文本, 写入列数取 data 长度与列数的较小值 |
| `QStringList getRowData(int row) const` | 整行读取文本 |
| `void setItemHeight(int ItemHeight)` / `int getItemHeight() const` | 每行项高度, 默认 35 |
| `void setHeaderMargin(int HeaderMargin)` / `int getHeaderMargin() const` | 表头文字边距, 默认 6 |
| `void setIsTransparent(bool IsTransparent)` / `bool getIsTransparent() const` | 背景是否透明, 默认 false |

**信号**:

- `void tableWidgetShow()`: 部件显示时发出, 适合在此设置列宽。
- `void tableWidgetHide()`: 部件隐藏时发出。
- `void itemClicked(QTableWidgetItem* item)` / `void cellChanged(int row, int column)`: 继承自 QTableWidget。

**注意**:

- 便捷接口 (insertRows / setRowData 等) 对越界参数一律静默忽略, 不抛错误也无返回值, 调用前需自行保证行列数正确。
- `setRowData` 只写入 `qMin(data.size(), columnCount())` 列, 多余数据被丢弃。
- 与 ElaTableView 相同, 默认隐藏网格线, 整行悬停高亮仅在 SelectRows 模式下生效, 列宽建议在 `tableWidgetShow` 信号槽中设置。
- 数据量大或需要复杂数据逻辑时, 改用 ElaTableView 搭配自定义模型。

### ElaTreeView

FluentUI 风格的树形视图, 默认开启展开收起动画, 适用于展示层级数据 (目录树, 组织结构等)。继承自 QTreeView, 需配合树形结构的 QAbstractItemModel 使用。

**头文件**: `#include "ElaTreeView.h"`

**基本用法**:

```cpp
#include <QHeaderView>
#include <QStandardItemModel>
#include <QWidget>

#include "ElaTreeView.h"
#include "ElaScrollBar.h"

void createTreeView(QWidget* parent)
{
    ElaTreeView* treeView = new ElaTreeView(parent);

    // 构造一个两层树模型
    QStandardItemModel* model = new QStandardItemModel(parent);
    model->setHorizontalHeaderLabels(QStringList() << "名称");
    QStandardItem* rootItem = new QStandardItem("根节点");
    rootItem->appendRow(new QStandardItem("子节点 1"));
    rootItem->appendRow(new QStandardItem("子节点 2"));
    model->appendRow(rootItem);
    treeView->setModel(model);

    // 调整项高度、表头边距与缩进
    treeView->setItemHeight(35);
    treeView->setHeaderMargin(5);
    treeView->setIndentation(20);

    // 表头字体
    QFont headerFont = treeView->header()->font();
    headerFont.setPixelSize(16);
    treeView->header()->setFont(headerFont);

    // 展开全部节点
    treeView->expandAll();

    // 可选: 外挂浮动滚动条
    ElaScrollBar* floatScrollBar = new ElaScrollBar(treeView->verticalScrollBar(), treeView);
    floatScrollBar->setIsAnimation(true);
}
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `explicit ElaTreeView(QWidget* parent = nullptr)` | 构造树形视图 |
| `void setItemHeight(int ItemHeight)` | 设置每项高度, 默认 35, 传入值须大于 0 否则忽略 |
| `int getItemHeight() const` | 获取每项高度 |
| `void setHeaderMargin(int HeaderMargin)` | 设置表头文字边距, 默认 5, 传入负值忽略 |
| `int getHeaderMargin() const` | 获取表头文字边距 |
| `void setModel(QAbstractItemModel* model)` | 绑定树形模型, 继承自 QTreeView |
| `void setIndentation(int i)` | 设置子层级缩进像素, 继承自 QTreeView |
| `void expandAll()` / `void collapseAll()` | 展开或收起全部节点, 继承自 QTreeView |
| `QHeaderView* header() const` | 访问表头以设置字体等, 继承自 QTreeView |

**信号**:

- `void expanded(const QModelIndex& index)` / `void collapsed(const QModelIndex& index)`: 继承自 QTreeView, 节点展开或收起时发出。
- `void clicked(const QModelIndex& index)`: 继承自 QAbstractItemView。

**注意**:

- 构造时已调用 `setAnimated(true)`, 展开收起自带动画; 数据量极大时可 `setAnimated(false)` 关闭以提升性能。
- 内置滚动条已开启动画并在动画结束时自动重排项布局, 无需手动处理。
- 项高度由内部 style 统一接管, 通过 `setItemHeight` 修改。

## 图形与屏幕采集

本章包含 Graphics View 框架的 Fluent 风格封装(视图、场景、图元、连线)以及两个平台专属的屏幕采集单例(Windows DXGI 与 macOS ScreenCaptureKit)。

### ElaGraphicsView

带缩放与平移交互的图形视图, 继承自 QGraphicsView。内置 Ctrl+滚轮缩放(带最大/最小缩放倍数限制)和按住 Alt 拖拽平移, 适合作为节点编辑器、拓扑图等场景的画布视图。

**头文件**: `#include "ElaGraphicsView.h"`

**基本用法**:

```cpp
#include "ElaGraphicsScene.h"
#include "ElaGraphicsView.h"

// 创建场景与视图, 构造时可直接传入场景
ElaGraphicsScene* scene = new ElaGraphicsScene(this);
scene->setSceneRect(0, 0, 1500, 1500);
ElaGraphicsView* view = new ElaGraphicsView(scene);
view->setFixedHeight(600);

// 限制缩放范围: 最大 5 倍, 最小 0.15 倍(即默认值)
view->setMaxTransform(5);
view->setMinTransform(0.15);
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `explicit ElaGraphicsView(QWidget* parent = nullptr)` | 构造空视图, 之后通过 setScene 绑定场景 |
| `explicit ElaGraphicsView(QGraphicsScene* scene, QWidget* parent = nullptr)` | 构造视图并绑定场景 |
| `void setMaxTransform(qreal MaxTransform)` | 设置 Ctrl+滚轮放大的最大缩放倍数, 默认 5 |
| `qreal getMaxTransform() const` | 获取最大缩放倍数 |
| `void setMinTransform(qreal MinTransform)` | 设置 Ctrl+滚轮缩小的最小缩放倍数, 默认 0.15 |
| `qreal getMinTransform() const` | 获取最小缩放倍数 |

**注意**:

- 按住 Ctrl 滚动滚轮进行缩放, 每格缩放系数为 1.1; 不按 Ctrl 时滚轮为默认的滚动条行为。
- 按住 Alt 键切换为 `ScrollHandDrag` 拖拽平移, 松开后恢复 `RubberBandDrag` 框选模式。
- 视图构造时已设置 `QGraphicsView::FullViewportUpdate`, 无需手动处理连线残影问题。

### ElaGraphicsScene

支持图元管理、图元连线和序列化的图形场景, 继承自 QGraphicsScene。内置多选、拖拽连线、删除等键盘交互, 并提供图元点击信号, 适合搭建节点连线编辑器。

**头文件**: `#include "ElaGraphicsScene.h"`

**基本用法**:

```cpp
#include "ElaDef.h"
#include "ElaGraphicsItem.h"
#include "ElaGraphicsScene.h"

ElaGraphicsScene* scene = new ElaGraphicsScene(this);
scene->setSceneRect(0, 0, 1500, 1500);

// 添加两个图元
ElaGraphicsItem* item1 = new ElaGraphicsItem();
item1->setWidth(100);
item1->setHeight(100);
item1->setMaxLinkPortCount(1);
ElaGraphicsItem* item2 = new ElaGraphicsItem();
item2->setWidth(100);
item2->setHeight(100);
scene->addItem(item1);
scene->addItem(item2);

// 开启端口占用检查后, 通过代码建立连线(端口 0 连接端口 0)
scene->setIsCheckLinkPort(true);
scene->addItemLink(item1, item2, 0, 0);

// 监听图元双击
connect(scene, &ElaGraphicsScene::mouseDoubleClickedItem, this, [=](ElaGraphicsItem* item) {
    qDebug() << "双击图元:" << item->getItemUID();
});

// 序列化场景到文件(默认路径 ./scene.bin)
scene->setSerializePath("./scene.bin");
scene->serialize();
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `void addItem(ElaGraphicsItem* item)` | 向场景添加图元 |
| `void removeItem(ElaGraphicsItem* item)` | 从场景移除图元 |
| `void removeSelectedItems()` | 移除当前选中的所有图元 |
| `QList<ElaGraphicsItem*> createAndAddItem(int width, int height, int count = 1)` | 批量创建指定尺寸的图元并加入场景, 返回创建的图元列表 |
| `QList<ElaGraphicsItem*> getSelectedElaItems() const` | 获取选中的 Ela 图元列表 |
| `QList<ElaGraphicsItem*> getElaItems()` | 获取场景内全部 Ela 图元 |
| `void selectAllItems()` | 全选场景内图元 |
| `void setSceneMode(ElaGraphicsSceneType::SceneMode mode)` | 设置场景模式: Default / DragMove / MultiSelect / ItemLink |
| `ElaGraphicsSceneType::SceneMode getSceneMode() const` | 获取当前场景模式 |
| `bool addItemLink(ElaGraphicsItem* item1, ElaGraphicsItem* item2, int port1 = 0, int port2 = 0)` | 在两个图元的指定端口间建立连线, 成功返回 true |
| `bool removeItemLink(ElaGraphicsItem* item1, ElaGraphicsItem* item2, int port1 = 0, int port2 = 0)` | 移除两个图元指定端口间的连线 |
| `QList<QVariantMap> getItemLinkList() const` | 获取当前全部连线信息(图元 UID 与端口的映射) |
| `void setIsCheckLinkPort(bool IsCheckLinkPort)` | 开启后 addItemLink 会检查端口占用, 已占用则连线失败 |
| `void setSerializePath(QString SerializePath)` | 设置序列化文件路径, 默认 "./scene.bin" |
| `void serialize()` / `void deserialize()` | 将场景图元与连线保存到文件 / 从文件恢复 |

**信号**:

| 信号 | 说明 |
| --- | --- |
| `void mouseLeftClickedItem(ElaGraphicsItem* item)` | 鼠标左键点击图元时发出 |
| `void mouseRightClickedItem(ElaGraphicsItem* item)` | 鼠标右键点击图元时发出 |
| `void mouseDoubleClickedItem(ElaGraphicsItem* item)` | 鼠标双击图元时发出 |
| `void showItemLink()` | ItemLink 模式下选中两个图元且已开启 IsCheckLinkPort 时发出, 供应用弹出端口选择界面后调用 addItemLink 完成连线 |

**注意**:

- 内置键盘交互: 按住 Ctrl 进入 MultiSelect 多选模式, 按住 Shift 进入 ItemLink 模式(从图元上拖拽出连线到目标图元), 按 Delete 删除选中图元, 松开按键恢复 Default 模式。
- addItemLink 对非法参数(空指针、自连、端口越界)返回 false; 连线成功后场景内部会自动创建 ElaGraphicsLineItem, 无需手动添加。
- 序列化使用 QDataStream 二进制格式, 路径由 SerializePath 属性指定, 打开文件失败时仅输出日志不抛异常。

### ElaGraphicsItem

场景中的基础图元, 继承自 QGraphicsObject。以图片形式绘制, 支持普通/选中两套图片、连接端口管理和自定义数据路由, 是 ElaGraphicsScene 连线体系的节点单元。

**头文件**: `#include "ElaGraphicsItem.h"`

**基本用法**:

```cpp
#include "ElaGraphicsItem.h"
#include "ElaGraphicsScene.h"

// 创建 100x100 的图元(也可用默认构造后再 setWidth/setHeight, 默认 50x50)
ElaGraphicsItem* item = new ElaGraphicsItem(100, 100);
item->setItemName("节点A");
// 设置普通与选中状态的显示图片
item->setItemImage(QImage(":/Resource/Image/node.png"));
item->setItemSelectedImage(QImage(":/Resource/Image/node_selected.png"));
// 该图元最多允许 4 条连线端口
item->setMaxLinkPortCount(4);

ElaGraphicsScene* scene = new ElaGraphicsScene(this);
scene->addItem(item);
item->setPos(200, 200);

// 查询端口占用情况
int freePortCount = item->getUnusedLinkPortCount();
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `explicit ElaGraphicsItem(QGraphicsItem* parent = nullptr)` | 构造默认图元, 尺寸 50x50 |
| `explicit ElaGraphicsItem(int width, int height, QGraphicsItem* parent = nullptr)` | 构造指定尺寸的图元 |
| `void setWidth(int Width)` / `int getWidth() const` | 设置/获取图元宽度 |
| `void setHeight(int Height)` / `int getHeight() const` | 设置/获取图元高度 |
| `void setItemImage(QImage ItemImage)` | 设置普通状态显示的图片 |
| `void setItemSelectedImage(QImage ItemSelectedImage)` | 设置选中状态显示的图片 |
| `void setItemName(QString ItemName)` / `QString getItemName() const` | 设置/获取图元名称 |
| `void setMaxLinkPortCount(int MaxLinkPortCount)` | 设置最大连接端口数, 默认 1 |
| `QString getItemUID() const` | 获取图元唯一标识 UID |
| `bool getLinkPortState(int portIndex) const` | 查询指定端口是否已被连线占用 |
| `int getUsedLinkPortCount() const` / `int getUnusedLinkPortCount() const` | 获取已用/空闲端口数量 |
| `QVector<int> getUsedLinkPort() const` / `QVector<int> getUnusedLinkPort() const` | 获取已用/空闲端口索引列表 |
| `void setDataRoutes(QVariantMap DataRoutes)` / `QVariantMap getDataRoutes() const` | 设置/获取图元携带的自定义数据路由 |

**注意**:

- 图元默认带有 `ItemIsMovable | ItemIsFocusable | ItemIsSelectable` 标志, 可直接拖动和选中。
- boundingRect 以图元中心为原点, 即 `QRect(-width/2, -height/2, width, height)`, setPos 定位的是图元中心。
- 普通与选中两套图片均有库内置默认图片, 未调用 setItemImage/setItemSelectedImage 时使用默认图片; 选中时绘制 ItemSelectedImage, 未选中时绘制 ItemImage。
- 端口状态由 ElaGraphicsScene 的连线操作自动维护, 一般只需读取, 不需要手动调用 setLinkPortState。

### ElaGraphicsLineItem

图元之间的贝塞尔曲线连线, 继承自 QGraphicsPathItem。既可绑定两个 ElaGraphicsItem 的端口(随图元移动自动重绘), 也可以直接指定起止坐标绘制自由曲线。

**头文件**: `#include "ElaGraphicsLineItem.h"`

**基本用法**:

```cpp
#include "ElaGraphicsItem.h"
#include "ElaGraphicsLineItem.h"
#include "ElaGraphicsScene.h"

ElaGraphicsScene* scene = new ElaGraphicsScene(this);
ElaGraphicsItem* item1 = new ElaGraphicsItem(100, 100);
ElaGraphicsItem* item2 = new ElaGraphicsItem(100, 100);
scene->addItem(item1);
scene->addItem(item2);
item2->setPos(300, 200);

// 方式一: 绑定两个图元的端口, 连线随图元移动
ElaGraphicsLineItem* line = new ElaGraphicsLineItem(item1, item2, 0, 0);
scene->QGraphicsScene::addItem(line);

// 方式二: 直接指定起止坐标绘制曲线
ElaGraphicsLineItem* freeLine = new ElaGraphicsLineItem(QPointF(0, 0), QPointF(200, 150));
scene->QGraphicsScene::addItem(freeLine);

// 判断连线是否关联指定图元
bool linked = line->isTargetLink(item1, item2);
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `explicit ElaGraphicsLineItem(ElaGraphicsItem* startItem, ElaGraphicsItem* endItem, int startItemPort, int endItemPort, QGraphicsItem* parent = nullptr)` | 构造绑定两个图元端口的连线 |
| `explicit ElaGraphicsLineItem(QPointF startPoint, QPointF endPoint, QGraphicsItem* parent = nullptr)` | 构造指定起止坐标的自由连线 |
| `bool isTargetLink(ElaGraphicsItem* item) const` | 判断连线是否关联该图元 |
| `bool isTargetLink(ElaGraphicsItem* item1, ElaGraphicsItem* item2) const` | 判断连线是否同时关联两个图元 |
| `bool isTargetLink(ElaGraphicsItem* item1, ElaGraphicsItem* item2, int port1, int port2) const` | 判断连线是否精确匹配两个图元的指定端口 |
| `void setStartPoint(QPointF StartPoint)` / `QPointF getStartPoint() const` | 设置/获取起点坐标(坐标构造方式下生效) |
| `void setEndPoint(QPointF EndPoint)` / `QPointF getEndPoint() const` | 设置/获取终点坐标(坐标构造方式下生效) |
| `ElaGraphicsItem* getStartItem() const` / `ElaGraphicsItem* getEndItem() const` | 获取连线绑定的起点/终点图元 |
| `int getStartItemPort() const` / `int getEndItemPort() const` | 获取起点/终点图元的端口索引 |

**注意**:

- 连线以三次贝塞尔曲线(cubicTo)绘制, 黑色 3 像素画笔。
- 通常不需要手动创建: 在 ElaGraphicsScene 中按住 Shift 拖拽连线或调用 `addItemLink()` 时, 场景会自动创建并管理 ElaGraphicsLineItem。
- 该类不继承 QObject, 属性接口只有 setter/getter, 没有属性变更信号, 不能用于信号槽连接。

### ElaDxgiManager

Windows 平台基于 DXGI Desktop Duplication 的屏幕采集单例, 继承自 QObject。支持选择显卡与输出屏幕、指定采集区域和帧率, 以 QImage 信号持续输出画面; 配套的 ElaDxgiScreen 控件可直接预览采集内容。

**头文件**: `#include "ElaDxgiManager.h"`

**基本用法**:

```cpp
#ifdef Q_OS_WIN
#include "ElaDxgiManager.h"

// 获取单例并配置采集参数
ElaDxgiManager* dxgiManager = ElaDxgiManager::getInstance();
dxgiManager->setDxDeviceID(0);                // 选择第 0 块显卡
dxgiManager->setOutputDeviceID(0);            // 选择该显卡的第 0 个输出屏幕
dxgiManager->setGrabArea(1920, 1080);         // 以屏幕中心为基准的 1920x1080 采集区域
dxgiManager->setGrabFrameRate(60);            // 采集帧率 60fps

// 使用配套预览控件显示画面
ElaDxgiScreen* dxgiScreen = new ElaDxgiScreen(this);
dxgiScreen->setFixedSize(1200, 678);

// 开始/停止采集
dxgiManager->startGrabScreen();
// dxgiManager->stopGrabScreen();

// 也可直接消费图像帧信号
connect(dxgiManager, &ElaDxgiManager::grabImageUpdate, this, [=](QImage img) {
    // 处理采集到的帧, 例如编码后推流
});
#endif
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `static ElaDxgiManager* getInstance()` | 获取全局单例, 构造函数私有 |
| `QStringList getDxDeviceList() const` | 获取显卡设备名称列表 |
| `QStringList getOutputDeviceList() const` | 获取当前显卡下的输出屏幕列表 |
| `bool setDxDeviceID(int dxID)` / `int getDxDeviceID() const` | 选择/获取采集使用的显卡, 成功返回 true |
| `bool setOutputDeviceID(int deviceID)` / `int getOutputDeviceID() const` | 选择/获取采集的输出屏幕, 成功返回 true |
| `void setGrabArea(int width, int height)` | 设置采集区域, 从屏幕中心向外延伸 |
| `void setGrabArea(int x, int y, int width, int height)` | 设置指定位置的采集区域 |
| `QRect getGrabArea() const` | 获取当前采集区域 |
| `void setGrabFrameRate(int frameRateValue)` / `int getGrabFrameRate() const` | 设置/获取采集帧率, 仅接受正值 |
| `void setTimeoutMsValue(int timeoutValue)` / `int getTimeoutMsValue() const` | 设置/获取单帧采集超时毫秒数 |
| `void startGrabScreen()` / `void stopGrabScreen()` | 启动/停止持续采集 |
| `bool getIsGrabScreen() const` | 查询是否正在采集 |
| `QImage grabScreenToImage() const` | 立即抓取一帧屏幕图像 |

**信号**:

| 信号 | 说明 |
| --- | --- |
| `void grabImageUpdate(QImage img)` | 持续采集期间每采到一帧发出一次 |

**注意**:

- 仅在 Windows 下可用, 头文件中的类声明被 `#ifdef Q_OS_WIN` 包裹, 跨平台代码必须做同样的条件编译; 库在 Windows 上链接 D3D11 与 DXGI。
- 配套控件 ElaDxgiScreen(继承 QWidget)自动连接 grabImageUpdate 显示画面, 提供 `setBorderRadius(int)`(默认 5)设置圆角, `setIsSyncGrabSize(bool)` 控制控件尺寸是否与采集区域同步。
- 切换显卡(setDxDeviceID)后输出屏幕列表会变化, 需要重新读取 getOutputDeviceList 并设置 OutputDeviceID。

### ElaScreenCaptureManager

macOS 平台基于 ScreenCaptureKit 的屏幕采集单例, 继承自 QObject, 是 ElaDxgiManager 在 macOS 上的对应实现。支持选择显示器、指定采集区域与帧率, 以 QImage 信号输出画面; 配套 ElaScreenCaptureScreen 控件用于预览。

**头文件**: `#include "ElaScreenCaptureManager.h"`

**基本用法**:

```cpp
#ifdef Q_OS_MAC
#include "ElaScreenCaptureManager.h"

// 获取单例并配置采集参数
ElaScreenCaptureManager* captureManager = ElaScreenCaptureManager::getInstance();
captureManager->setDisplayID(0);           // 选择第 0 个显示器
captureManager->setGrabArea(1920, 1080);   // 设置采集区域
captureManager->setGrabFrameRate(60);      // 采集帧率 60fps

// 使用配套预览控件显示画面
ElaScreenCaptureScreen* captureScreen = new ElaScreenCaptureScreen(this);
captureScreen->setFixedSize(1200, 678);

// 开始/停止采集
captureManager->startGrabScreen();
// captureManager->stopGrabScreen();

connect(captureManager, &ElaScreenCaptureManager::grabImageUpdate, this, [=](QImage img) {
    // 处理采集到的帧
});
#endif
```

**常用 API**:

| API | 说明 |
| --- | --- |
| `static ElaScreenCaptureManager* getInstance()` | 获取全局单例, 构造函数私有 |
| `QStringList getDisplayList() const` | 获取显示器名称列表 |
| `bool setDisplayID(int displayID)` / `int getDisplayID() const` | 选择/获取采集的显示器, 成功返回 true |
| `void setGrabArea(int width, int height)` | 设置采集区域尺寸 |
| `void setGrabArea(int x, int y, int width, int height)` | 设置指定位置的采集区域 |
| `QRect getGrabArea() const` | 获取当前采集区域 |
| `void setGrabFrameRate(int frameRateValue)` / `int getGrabFrameRate() const` | 设置/获取采集帧率 |
| `void startGrabScreen()` / `void stopGrabScreen()` | 启动/停止持续采集 |
| `bool getIsGrabScreen() const` | 查询是否正在采集 |
| `QImage grabScreenToImage() const` | 立即抓取一帧屏幕图像 |

**信号**:

| 信号 | 说明 |
| --- | --- |
| `void grabImageUpdate(QImage img)` | 持续采集期间每采到一帧发出一次 |

**注意**:

- 仅在 macOS 下可用, 头文件中的类声明被 `#ifdef Q_OS_MAC` 包裹; 库在 macOS 上链接 ScreenCaptureKit 与 ApplicationServices 框架。
- ScreenCaptureKit 需要用户在系统设置的"隐私与安全性 - 屏幕录制"中为应用授权, 首次采集会触发系统授权弹窗, 未授权时无法获取画面。
- 配套控件 ElaScreenCaptureScreen(继承 QWidget)自动显示采集画面, 提供 `setBorderRadius(int)` 设置圆角, `setIsSyncGrabSize(bool)` 控制控件尺寸是否与采集区域同步。
- 与 ElaDxgiManager 接口对齐, 跨平台应用可通过条件编译在两者间切换, 参见示例工程 ExamplePage/T_ElaScreen.cpp。
