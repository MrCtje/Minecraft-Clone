#version 130

in vec2 ex_texCoord;

out vec4 out_Color;

uniform sampler2D texture;

void main(void)
{
  out_Color = vec4(texture2D(texture, ex_texCoord).rgba);
//    out_Color = vec4(0,0,1,1);
}
