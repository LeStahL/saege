void Line(in vec2 x, in vec2 p1, in vec2 p2, out float d)
{
    vec2 a = p2-p1;
    d = length(x-mix(p1, p2, clamp(dot(x-p1, a)/dot(a,a),0.0,1.0)));
}
