
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

    bool isKeyPressed = sf::Keyboard::isKeyPressed(sf::Key::Enter);
    sf::Keyboard::setVirtualKeyboardVisible(false);
}
