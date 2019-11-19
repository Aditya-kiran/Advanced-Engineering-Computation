attribute vec3 vertex;
attribute vec4 color;

varying vec4 colorOut;

void main()
{
	gl_Position=vec4(vertex,1.0);
}
