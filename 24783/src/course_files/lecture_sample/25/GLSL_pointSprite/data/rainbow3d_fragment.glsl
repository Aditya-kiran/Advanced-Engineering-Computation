varying vec3 vertexOut;
void main()
{
	float pi=3.14159265;
	gl_FragColor=vec4((1.0+sin(vertexOut.x))/2.0,(1.0+sin(pi/2.0+vertexOut.y))/2.0,(1.0+sin(pi+vertexOut.z))/2.0,1.0);
}
