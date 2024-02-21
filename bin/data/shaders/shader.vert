#version 450

//--------------------------------------------------------------
// oF default
//--------------------------------------------------------------
in vec4 color;
in vec4 position;
in vec4 normal;
in vec2 texcoord;

out vec4 vColor;
out vec4 vPosition;
out vec4 vNormal;
out vec2 vTexCoord;

uniform mat4 modelViewProjectionMatrix;
uniform mat4 modelViewMatrix;


void main()
{
    mat4 normalMatrix = inverse(transpose(modelViewMatrix));

    vPosition = modelViewMatrix * position;
    // vPosition = position;
    vColor = vec4(1.0, 0.0, 1.0, 1.0);
    vNormal = normalMatrix * normal;
    vTexCoord = texcoord;

    gl_Position = modelViewProjectionMatrix * position;
}