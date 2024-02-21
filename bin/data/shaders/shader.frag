#version 450
precision highp float;

in vec4 vColor;
in vec4 vPosition;
in vec4 vNormal;
in vec2 vTexCoord;

layout (location = 0) out vec4 fragColor;

uniform float _Alpha;
uniform sampler2D _Texture;
uniform int _IsBorder;


float box(vec2 p,vec2 c,float size)
{
    float len=max(abs(p-c).x,abs(p-c).y);
    return step(len,size);
}

void main()
{
    vec2 uv = vTexCoord.st;

    vec4 c = vec4(0);

    vec4 tex = texture(_Texture, uv);
    c = tex;

    // float borderSizeY = 0.007;
    // float borderSizeX = borderSizeY * (96 / 36);
    // float borderSizeY = 0.0075;
    float borderSizeY = 0.01;
    float borderSizeX = borderSizeY * (76.8 / 45.0);
    // float borderSizeX = 0.02;
    // float borderSizeY = borderSizeX * (76.8 / 45.0);

    if (_IsBorder == 1)
    {
        c = (uv.x < borderSizeX || uv.x > 1.0 - borderSizeX) ? vec4(0.0, 0.0, 0.0, 1.0) : c;
        c = (uv.y < borderSizeY || uv.y > 1.0 - borderSizeY) ? vec4(0.0, 0.0, 0.0, 1.0) : c;
    }

    // c = vec4(box(vec2(uv * 2.0 - 1.0), vec2(0.0, 0.0), 0.95));

    c.a = _Alpha;
    // c.a = 0.2;

    fragColor = c;
}