attribute vec2 vertex;
attribute vec4 color;

// Map (0,0) -> (-1,1)
//     (0,600) -> (-1,-1)
//     (800,0) -> (1,1)
//     (800,600) -> (1,-1)

void main(void)
{
	gl_Position=vec4(vertex,0,1); // w must be 1.  Not 0.
}
