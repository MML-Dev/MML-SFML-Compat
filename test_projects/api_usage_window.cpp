
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
