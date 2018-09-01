
// Including all files to make sure we don't delete some by mistake

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/BlendMode.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/ConvexShape.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Export.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Glsl.hpp>
#include <SFML/Graphics/Glyph.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Shader.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Transform.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/VertexBuffer.hpp>
#include <SFML/Graphics/View.hpp>

void test_blendmode_hpp()
{
    sf::BlendMode::Factor factor;
    factor = sf::BlendMode::Zero;
    factor = sf::BlendMode::One;
    factor = sf::BlendMode::SrcColor;
    factor = sf::BlendMode::OneMinusSrcColor;
    factor = sf::BlendMode::DstColor;
    factor = sf::BlendMode::OneMinusDstColor;
    factor = sf::BlendMode::SrcAlpha;
    factor = sf::BlendMode::OneMinusSrcAlpha;
    factor = sf::BlendMode::DstAlpha;
    factor = sf::BlendMode::OneMinusDstAlpha;
    
    sf::BlendMode::Equation equation;
    equation = sf::BlendMode::Add;
    equation = sf::BlendMode::Subtract;
    equation = sf::BlendMode::ReverseSubtract;
    
    sf::BlendMode defaultMode;
    sf::BlendMode mode(factor, factor, equation);
    sf::BlendMode custom(factor, factor, equation, factor, factor, equation);
    
    mode.colorSrcFactor;
    mode.colorDstFactor;
    mode.colorEquation;
    mode.alphaSrcFactor;
    mode.alphaDstFactor;
    mode.alphaEquation;
    
    bool r = mode == mode;
    r = mode != mode;
    
    mode = sf::BlendAlpha;
    mode = sf::BlendAdd;
    mode = sf::BlendMultiply;
    mode = sf::BlendNone;
}

void test_circleshape_hpp()
{
    sf::CircleShape shape((float()), std::size_t());
    shape.setRadius(float());
    float f = shape.getRadius();
    
    shape.setPointCount(std::size_t());
    std::size_t c = shape.getPointCount();
    sf::Vector2f p = shape.getPoint(std::size_t());
}

void test_color_hpp()
{
    sf::Color color;
    color = sf::Color(sf::Uint8(), sf::Uint8(), sf::Uint8(), sf::Uint8());
    color = sf::Color(sf::Uint32());
    sf::Uint32 i = color.toInteger();
    color = sf::Color::Black;
    color = sf::Color::White;
    color = sf::Color::Red;
    color = sf::Color::Green;
    color = sf::Color::Blue;
    color = sf::Color::Yellow;
    color = sf::Color::Magenta;
    color = sf::Color::Cyan;
    color = sf::Color::Transparent;
    
    sf::Uint8 r = color.r;
    sf::Uint8 g = color.g;
    sf::Uint8 b = color.b;
    sf::Uint8 a = color.a;
    
    bool res = color == color;
    res = color != color;
    color = color + color;
    color = color - color;
    color = color * color;
    color += color;
    color -= color;
    color *= color;
}

void test_convexshape_hpp()
{
    sf::ConvexShape shape((std::size_t()));
    shape.setPointCount(std::size_t());
    std::size_t c = shape.getPointCount();
    shape.setPoint(std::size_t(), sf::Vector2f());
    sf::Vector2f v = shape.getPoint(std::size_t());
}

void test_font_hpp()
{
    sf::Font::Info info;
    info.family = std::string();
    
    sf::Font font;
    sf::Font copy(font);
    copy = font;
    bool r = font.loadFromFile(std::string());
    r = font.loadFromMemory((const void*)nullptr, std::size_t());
    sf::FileInputStream stream;
    r = font.loadFromStream(stream);
    info = font.getInfo();
    
    const sf::Glyph& glyph = font.getGlyph(sf::Uint32(), (unsigned int){}, bool(), float());
    float f = font.getKerning(sf::Uint32(), sf::Uint32(), (unsigned int){});
    f = font.getLineSpacing((unsigned int){});
    f = font.getUnderlinePosition((unsigned int){});
    f = font.getUnderlineThickness((unsigned int){});
    const sf::Texture& tex = font.getTexture((unsigned int){});
}

void test_glsl_hpp()
{
    sf::Glsl::Vec2 v2;
    sf::Glsl::Ivec2 iv2;
    sf::Glsl::Bvec2 bv2;
    sf::Glsl::Vec3 v3;
    sf::Glsl::Ivec3 iv3;
    sf::Glsl::Bvec3 bv3;
    sf::Glsl::Vec4 v4;
    sf::Glsl::Ivec4 iv4;
    sf::Glsl::Bvec4 bv4;
    sf::Glsl::Mat3 m3((const float*){});
    sf::Glsl::Mat4 m4((const float*){});
}

void test_glyph_hpp()
{
    sf::Glyph glyph;
    float f = glyph.advance;
    sf::FloatRect fr = glyph.bounds;
    sf::IntRect ir = glyph.textureRect;
}

void test_image_hpp()
{
    sf::Image img;
    img.create((unsigned int){}, (unsigned int){}, sf::Color::Blue);
    img.create((unsigned int){}, (unsigned int){}, (const sf::Uint8 *)nullptr);
    bool b = img.loadFromFile(std::string());
    b = img.loadFromMemory((const void*)nullptr, std::size_t());
    sf::FileInputStream stream;
    b = img.loadFromStream(stream);
    b = img.saveToFile(std::string());
    sf::Vector2u sz = img.getSize();
    img.createMaskFromColor(sf::Color::Blue, sf::Uint8());
    img.copy(img, (unsigned int){}, (unsigned int){}, sf::IntRect(), bool());
    img.setPixel((unsigned int){}, (unsigned int){}, sf::Color::Blue);
    sf::Color c = img.getPixel((unsigned int){}, (unsigned int){});
    const sf::Uint8* p = img.getPixelsPtr();
    img.flipHorizontally();
    img.flipVertically();
}

void test_primitivetype_hpp()
{
    sf::PrimitiveType type;
    type = sf::Points;
    type = sf::Lines;
    type = sf::LineStrip;
    type = sf::Triangles;
    type = sf::TriangleStrip;
    type = sf::TriangleFan;
    type = sf::Quads;
    
    // Were deprecated and are removed from MML:
//    type = sf::LinesStrip;
//    type = sf::TrianglesStrip;
//    type = sf::TrianglesFan;
}

