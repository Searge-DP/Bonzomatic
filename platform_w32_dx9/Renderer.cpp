#ifdef _WIN32
#include <windows.h>
#endif
#include <d3d9.h>
#include "../Renderer.h"

#define STBI_HEADER_FILE_ONLY
#include <stb_image.c>
#include "../external/scintilla/include/Scintilla.h"

namespace Renderer
{
  char defaultShader[65536] = 
    "float4 ps_main( float2 TexCoord : TEXCOORD0 )\n"
    "{\n"
    "  float2 uv = TexCoord;\n"
    "  uv -= 0.5;\n"
    "  uv /= float2(v2Resolution.y / v2Resolution.x, 1);\n"
    "\n"
    "  float2 m;\n"
    "  m.x = atan(uv.x / uv.y) / 3.14;\n"
    "  m.y = 1 / length(uv) * .2;\n"
    "  float d = m.y;\n"
    "\n"
    "  float f = tex2D( texFFT, d ).r * 100;\n"
    "  m.x += sin( fGlobalTime ) * 0.1;\n"
    "  m.y += fGlobalTime * 0.25;\n"
    "\n"
    "  float4 t = tex2D( texTex2, m.xy ) * d; // or /d\n"
    "  return f + t;// + uv.xyxy * 0.5 * (sin( fGlobalTime ) + 1.5);\n"
    "}";

  bool run = true;

  int nWidth = 0;
  int nHeight = 0;
  bool Open( RENDERER_SETTINGS * settings )
  {
    return true;
  }

  KeyEvent keyEventBuffer[512];
  int keyEventBufferCount = 0;
  MouseEvent mouseEventBuffer[512];
  int mouseEventBufferCount = 0;
  void StartFrame()
  {
  }
  void EndFrame()
  {
  }
  bool WantsToQuit()
  {
    return !run;
  }
  void Close()
  {
  }

  void RenderFullscreenQuad()
  {
  }

  bool ReloadShader( char * szShaderCode, int nShaderCodeSize, char * szErrorBuffer, int nErrorBufferSize )
  {
    return true;
  }

  void SetShaderConstant( char * szConstName, float x )
  {
  }

  void SetShaderConstant( char * szConstName, float x, float y )
  {
  }

  struct DX9Texture : public Texture
  {
  };

  int textureUnit = 0;
  Texture * CreateRGBA8TextureFromFile( char * szFilename )
  {
    DX9Texture * tex = new DX9Texture();
    tex->width = 0;
    tex->height = 0;
    tex->type = TEXTURETYPE_2D;
    return tex;
  }

  Texture * Create1DR32Texture( int w )
  {
    DX9Texture * tex = new DX9Texture();
    tex->width = w;
    tex->height = 1;
    tex->type = TEXTURETYPE_1D;
    return tex;
  }

  void SetShaderTexture( char * szTextureName, Texture * tex )
  {
  }

  bool UpdateR32Texture( Texture * tex, float * data )
  {
    return true;
  }

  void StartTextRendering()
  {
  }
  void SetTextRenderingViewport( Scintilla::PRectangle rect )
  {
  }
  void EndTextRendering()
  {
  }

  Texture * CreateA8TextureFromData( int w, int h, unsigned char * data )
  {
    DX9Texture * tex = new DX9Texture();
    tex->width = w;
    tex->height = 1;
    tex->type = TEXTURETYPE_1D;
    return tex;
  }

  void ReleaseTexture( Texture * tex )
  {
  }

  void BindTexture( Texture * tex )
  {
  }

  void RenderQuad( Vertex & a, Vertex & b, Vertex & c, Vertex & d )
  {
  }

  void RenderLine( Vertex & a, Vertex & b )
  {
  }

}