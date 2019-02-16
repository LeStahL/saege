void Repeat(in vec2 x, in vec2 d, out vec2 y)
{
    y = mod(x, d)-.5*d;
}
