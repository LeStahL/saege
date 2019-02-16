void Box(in vec2 x, in vec2 b, out float d)
{
    b = abs(x) - b;
    d = length(max(b,c.yy)) + min(max(b.x,b.y),0.0);
}
