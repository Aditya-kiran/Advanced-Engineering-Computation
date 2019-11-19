attribute vec2 param;

uniform mat4 projection,modelView;
uniform vec3 ctp[16];

void main()
{
    gl_Position=vec4(param,0,1);
}
