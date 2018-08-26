
// Including all files to make sure we don't delete some by mistake

#include <SFML/Window.hpp>
#include <SFML/Window/Clipboard.hpp>
#include <SFML/Window/Context.hpp>
#include <SFML/Window/ContextSettings.hpp>
#include <SFML/Window/Cursor.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Export.hpp>
#include <SFML/Window/GlResource.hpp>
#include <SFML/Window/Joystick.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Sensor.hpp>
#include <SFML/Window/Touch.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/Window.hpp>
#include <SFML/Window/WindowHandle.hpp>
#include <SFML/Window/WindowStyle.hpp>

// Clipboard.hpp
void test_clipboard()
{
    sf::String str = sf::Clipboard::getString();
    sf::Clipboard::setString(str);
}

// Context.hpp
void test_context()
{
    sf::Context context;
    context.setActive(true);
    const sf::ContextSettings& settings = context.getSettings();
    bool isAvailable = sf::Context::isExtensionAvailable("test");
    sf::GlFunctionPointer funcPtr = sf::Context::getFunction("someFunc");
    const sf::Context* contextPtr = sf::Context::getActiveContext();
    sf::Uint64 id = sf::Context::getActiveContextId();

    sf::Context context2(settings, 20u, 20u);
}

// ContextSettings.hpp
void test_context_settings()
{
    std::initializer_list<sf::ContextSettings::Attribute> var1 = {
        sf::ContextSettings::Default,
        sf::ContextSettings::Core,
        sf::ContextSettings::Debug
    };

    sf::ContextSettings settings(0u, 0u, 0u, 1u, 1u, sf::ContextSettings::Default, false);
    settings.depthBits = 1u;
    settings.stencilBits = 1u;
    settings.antialiasingLevel = 1u;
    settings.majorVersion = 1u;
    settings.minorVersion = 0u;
    settings.attributeFlags = sf::Uint32(0);
    settings.sRgbCapable = false;
}

// Cursor.hpp
void test_cursor()
{
    std::initializer_list<sf::Cursor::Type> cursorTypes = {
        sf::Cursor::Arrow,
        sf::Cursor::ArrowWait,
        sf::Cursor::Wait,
        sf::Cursor::Text,
        sf::Cursor::Hand,
        sf::Cursor::SizeHorizontal,
        sf::Cursor::SizeVertical,
        sf::Cursor::SizeTopLeftBottomRight,
        sf::Cursor::SizeBottomLeftTopRight,
        sf::Cursor::SizeAll,
        sf::Cursor::Cross,
        sf::Cursor::Help,
        sf::Cursor::NotAllowed
    };

    sf::Cursor cursor;

    sf::Uint8* pixels = nullptr;
    cursor.loadFromPixels(pixels, sf::Vector2u(), sf::Vector2u());
    cursor.loadFromSystem(sf::Cursor::Arrow);
}

// Event.hpp
void test_event()
{
    sf::Event::SizeEvent sizeEvent;
    sizeEvent.width = 0u;
    sizeEvent.height = 0u;

    sf::Event::KeyEvent keyEvent;
    keyEvent.code = sf::Keyboard::Enter;
    keyEvent.alt = true;
    keyEvent.control = true;
    keyEvent.shift = true;
    keyEvent.system = true;

    sf::Event::TextEvent textEvent;
    textEvent.unicode = sf::Uint32(0);

    sf::Event::MouseMoveEvent mouseMoveEvent;
    mouseMoveEvent.x = 0;
    mouseMoveEvent.y = 0;

    sf::Event::MouseButtonEvent mouseButtonEvent;
    mouseButtonEvent.button = sf::Mouse::Left;
    mouseButtonEvent.x = 0;
    mouseButtonEvent.y = 0;

    sf::Event::MouseWheelEvent mouseWheelEvent;
    mouseWheelEvent.delta = 0;
    mouseWheelEvent.x = 0;
    mouseWheelEvent.y = 0;

    sf::Event::MouseWheelScrollEvent mouseWheelScrollEvent;
    mouseWheelScrollEvent.wheel = sf::Mouse::VerticalWheel;
    mouseWheelScrollEvent.delta = 0.0f;
    mouseWheelScrollEvent.x = 0;
    mouseWheelScrollEvent.y = 0;

    sf::Event::JoystickConnectEvent joystickConnectEvent;
    joystickConnectEvent.joystickId = 0u;

    sf::Event::JoystickMoveEvent joystickMoveEvent;
    joystickMoveEvent.joystickId = 0u;
    joystickMoveEvent.axis = sf::Joystick::PovX;
    joystickMoveEvent.position = 0.f;

    sf::Event::JoystickButtonEvent joystickButtonEvent;
    joystickButtonEvent.joystickId = 0u;
    joystickButtonEvent.button = 0u;

    sf::Event::TouchEvent touchEvent;
    touchEvent.finger = 0u;
    touchEvent.x = 0;
    touchEvent.y = 0;

    sf::Event::SensorEvent sensorEvent;
    sensorEvent.type = sf::Sensor::Accelerometer;
    sensorEvent.x = 0.f;
    sensorEvent.y = 0.f;
    sensorEvent.z = 0.f;

    std::initializer_list<sf::Event::EventType> eventTypes = {
        sf::Event::Closed,
        sf::Event::Resized,
        sf::Event::LostFocus,
        sf::Event::GainedFocus,
        sf::Event::TextEntered,
        sf::Event::KeyPressed,
        sf::Event::KeyReleased,
        sf::Event::MouseWheelMoved,
        sf::Event::MouseWheelScrolled,
        sf::Event::MouseButtonPressed,
        sf::Event::MouseButtonReleased,
        sf::Event::MouseMoved,
        sf::Event::MouseEntered,
        sf::Event::MouseLeft,
        sf::Event::JoystickButtonPressed,
        sf::Event::JoystickButtonReleased,
        sf::Event::JoystickMoved,
        sf::Event::JoystickConnected,
        sf::Event::JoystickDisconnected,
        sf::Event::TouchBegan,
        sf::Event::TouchMoved,
        sf::Event::TouchEnded,
        sf::Event::SensorChanged,

        sf::Event::Count
    };

    sf::Event event;
    event.type = sf::Event::Closed;

    event.size = sizeEvent;
    event.key = keyEvent;
    event.text = textEvent;
    event.mouseMove = mouseMoveEvent;
    event.mouseButton = mouseButtonEvent;
    event.mouseWheel = mouseWheelEvent;
    event.mouseWheelScroll = mouseWheelScrollEvent;
    event.joystickMove = joystickMoveEvent;
    event.joystickButton = joystickButtonEvent;
    event.joystickConnect = joystickConnectEvent;
    event.touch = touchEvent;
    event.sensor = sensorEvent;
}

// Joystick.hpp
void test_joystick()
{
    std::initializer_list<int> joystickCapabilities = {
        sf::Joystick::Count,
        sf::Joystick::ButtonCount,
        sf::Joystick::AxisCount
    };

    std::initializer_list<sf::Joystick::Axis> axes = {
        sf::Joystick::X,
        sf::Joystick::Y,
        sf::Joystick::Z,
        sf::Joystick::R,
        sf::Joystick::U,
        sf::Joystick::V,
        sf::Joystick::PovX,
        sf::Joystick::PovY
    };

    sf::Joystick::Identification id;
    id.name = sf::String();
    id.vendorId = 0u;
    id.productId = 0u;

    unsigned int joystickId = 0u;
    unsigned int buttonId = 0u;

    bool isConnected = sf::Joystick::isConnected(joystickId);
    unsigned int buttonCount = sf::Joystick::getButtonCount(joystickId);
    bool hasAxis = sf::Joystick::hasAxis(joystickId, sf::Joystick::X);
    bool isButtonPressed = sf::Joystick::isButtonPressed(joystickId, buttonId);
    float axisPosition = sf::Joystick::getAxisPosition(joystickId, sf::Joystick::X);
    id = sf::Joystick::getIdentification(joystickId);
    sf::Joystick::update();
}

// Keyboard.hpp
void test_keyboard()
{
    std::initializer_list<sf::Keyboard::Key> keys = {
        sf::Keyboard::Unknown,
        sf::Keyboard::A,
        sf::Keyboard::B,
        sf::Keyboard::C,
        sf::Keyboard::D,
        sf::Keyboard::E,
        sf::Keyboard::F,
        sf::Keyboard::G,
        sf::Keyboard::H,
        sf::Keyboard::I,
        sf::Keyboard::J,
        sf::Keyboard::K,
        sf::Keyboard::L,
        sf::Keyboard::M,
        sf::Keyboard::N,
        sf::Keyboard::O,
        sf::Keyboard::P,
        sf::Keyboard::Q,
        sf::Keyboard::R,
        sf::Keyboard::S,
        sf::Keyboard::T,
        sf::Keyboard::U,
        sf::Keyboard::V,
        sf::Keyboard::W,
        sf::Keyboard::X,
        sf::Keyboard::Y,
        sf::Keyboard::Z,
        sf::Keyboard::Num0,
        sf::Keyboard::Num1,
        sf::Keyboard::Num2,
        sf::Keyboard::Num3,
        sf::Keyboard::Num4,
        sf::Keyboard::Num5,
        sf::Keyboard::Num6,
        sf::Keyboard::Num7,
        sf::Keyboard::Num8,
        sf::Keyboard::Num9,
        sf::Keyboard::Escape,
        sf::Keyboard::LControl,
        sf::Keyboard::LShift,
        sf::Keyboard::LAlt,
        sf::Keyboard::LSystem,
        sf::Keyboard::RControl,
        sf::Keyboard::RShift,
        sf::Keyboard::RAlt,
        sf::Keyboard::RSystem,
        sf::Keyboard::Menu,
        sf::Keyboard::LBracket,
        sf::Keyboard::RBracket,
        sf::Keyboard::Semicolon,
        sf::Keyboard::Comma,
        sf::Keyboard::Period,
        sf::Keyboard::Quote,
        sf::Keyboard::Slash,
        sf::Keyboard::Backslash,
        sf::Keyboard::Tilde,
        sf::Keyboard::Equal,
        sf::Keyboard::Hyphen,
        sf::Keyboard::Space,
        sf::Keyboard::Enter,
        sf::Keyboard::Backspace,
        sf::Keyboard::Tab,
        sf::Keyboard::PageUp,
        sf::Keyboard::PageDown,
        sf::Keyboard::End,
        sf::Keyboard::Home,
        sf::Keyboard::Insert,
        sf::Keyboard::Delete,
        sf::Keyboard::Add,
        sf::Keyboard::Subtract,
        sf::Keyboard::Multiply,
        sf::Keyboard::Divide,
        sf::Keyboard::Left,
        sf::Keyboard::Right,
        sf::Keyboard::Up,
        sf::Keyboard::Down,
        sf::Keyboard::Numpad0,
        sf::Keyboard::Numpad1,
        sf::Keyboard::Numpad2,
        sf::Keyboard::Numpad3,
        sf::Keyboard::Numpad4,
        sf::Keyboard::Numpad5,
        sf::Keyboard::Numpad6,
        sf::Keyboard::Numpad7,
        sf::Keyboard::Numpad8,
        sf::Keyboard::Numpad9,
        sf::Keyboard::F1,
        sf::Keyboard::F2,
        sf::Keyboard::F3,
        sf::Keyboard::F4,
        sf::Keyboard::F5,
        sf::Keyboard::F6,
        sf::Keyboard::F7,
        sf::Keyboard::F8,
        sf::Keyboard::F9,
        sf::Keyboard::F10,
        sf::Keyboard::F11,
        sf::Keyboard::F12,
        sf::Keyboard::F13,
        sf::Keyboard::F14,
        sf::Keyboard::F15,
        sf::Keyboard::Pause,

        sf::Keyboard::KeyCount,

        // deprecated...
        sf::Keyboard::Dash,
        sf::Keyboard::BackSpace,
        sf::Keyboard::BackSlash,
        sf::Keyboard::SemiColon,
        sf::Keyboard::Return
    };

    bool isKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Enter);
    sf::Keyboard::setVirtualKeyboardVisible(false);
}

// Mouse.hpp
void test_mouse()
{
    std::initializer_list<sf::Mouse::Button> buttons = {
        sf::Mouse::Left,
        sf::Mouse::Right,
        sf::Mouse::Middle,
        sf::Mouse::XButton1,
        sf::Mouse::XButton2,

        sf::Mouse::ButtonCount
    };

    std::initializer_list<sf::Mouse::Wheel> wheels = {
        sf::Mouse::VerticalWheel,
        sf::Mouse::HorizontalWheel
    };

    bool isButtonPressed = sf::Mouse::isButtonPressed(sf::Mouse::Left);
    sf::Vector2i position = sf::Mouse::getPosition();

    sf::Window window;

    position = sf::Mouse::getPosition(window);

    sf::Mouse::setPosition(position);
    sf::Mouse::setPosition(position, window);
}

// Sensor.hpp
void test_sensor()
{
    std::initializer_list<sf::Sensor::Type> sensorTypes = {
        sf::Sensor::Accelerometer,
        sf::Sensor::Gyroscope,
        sf::Sensor::Magnetometer,
        sf::Sensor::Gravity,
        sf::Sensor::UserAcceleration,
        sf::Sensor::Orientation,
        sf::Sensor::Count
    };

    bool isAvailable = sf::Sensor::isAvailable(sf::Sensor::Accelerometer);
    sf::Sensor::setEnabled(sf::Sensor::Accelerometer, false);
    sf::Vector3f value = sf::Sensor::getValue(sf::Sensor::Accelerometer);
}

// Touch.hpp
void test_touch()
{
    unsigned int finger = 0u;
    bool isDown = sf::Touch::isDown(finger);
    sf::Vector2i position = sf::Touch::getPosition(finger);

    sf::Window window;
    position = sf::Touch::getPosition(finger, window);
}

// VideoMode.hpp
void test_videomode()
{
    sf::VideoMode videoMode;
    sf::VideoMode videoMode2(10u, 10u);
    sf::VideoMode videoMode3(10u, 10u, 32);

    videoMode = sf::VideoMode::getDesktopMode();

    const std::vector<sf::VideoMode>& modes = sf::VideoMode::getFullscreenModes();
    bool isValid = videoMode.isValid();

    videoMode.width = 10u;
    videoMode.height = 10u;
    videoMode.bitsPerPixel = 32;

    bool test = (videoMode == videoMode2);
    test = (videoMode != videoMode2);
    test = (videoMode < videoMode2);
    test = (videoMode > videoMode2);
    test = (videoMode <= videoMode2);
    test = (videoMode >= videoMode2);
}

// Window.hpp

void test_window()
{
    sf::Window window;

    sf::VideoMode videoMode;
    sf::String title;
    sf::Uint32 style;
    sf::ContextSettings contextSettings;

    sf::Window window2(videoMode, title);
    sf::Window window3(videoMode, title, style);
    sf::Window window4(videoMode, title, style, contextSettings);

    sf::WindowHandle handle;

    sf::Window window5(handle);
    sf::Window window6(handle, contextSettings);

    window.create(videoMode, title);
    window.create(videoMode, title, style);
    window.create(videoMode, title, style, contextSettings);

    window.create(handle);
    window.create(handle, contextSettings);

    window.close();

    bool isOpen = window.isOpen();

    contextSettings = window.getSettings();

    sf::Event event;

    bool hasEvent = window.pollEvent(event);
    bool succeded = window.waitEvent(event);

    sf::Vector2i position = window.getPosition();
    window.setPosition(position);

    sf::Vector2u size = window.getSize();
    window.setSize(size);

    window.setTitle(title);

    window.setIcon(32u, 32u, (const sf::Uint8*)nullptr);

    window.setVisible(false);
    window.setVerticalSyncEnabled(false);
    window.setMouseCursorGrabbed(false);

    sf::Cursor cursor;
    window.setMouseCursor(cursor);

    window.setKeyRepeatEnabled(false);

    window.setFramerateLimit(60u);
    window.setJoystickThreshold(0.f);

    succeded = window.setActive();
    succeded = window.setActive(false);

    window.requestFocus();

    bool hasFocus = window.hasFocus();

    window.display();

    handle = window.getSystemHandle();
}

// test if there are still protected virtual methods
struct WindowDerived : sf::Window
{
    void onCreate() override {};
    void onResize() override {};
};

// WindowStyle.hpp
void test_window_style()
{
    std::initializer_list<int> styles = {
        sf::Style::None,
        sf::Style::Titlebar,
        sf::Style::Resize,
        sf::Style::Close,
        sf::Style::Fullscreen,
        sf::Style::Default
    };
}
