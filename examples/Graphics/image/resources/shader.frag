#version 120

uniform sampler2D texture;

varying vec2 fragTexCoord;

void main(void)
{
    gl_FragColor = texture2D(texture, fragTexCoord);
}
