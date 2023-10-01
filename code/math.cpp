#pragma once

Meta_Parse_Struct(0);
union Vec2 {
	struct {
		float x, y; // @V0
	};

	struct {
		float w, h; // @Ignore
	};

	struct {
		float min, max; // @Ignore
	};

	float e[2]; // @Ignore
};

Meta_Parse_Struct(0);
union Vec2i {
	struct {
		int x, y; // @V0
	};

	struct {
		int w, h; // @Ignore
	};

	struct {
		int min, max; // @Ignore
	};

	int e[2]; // @Ignore
};

Meta_Parse_Struct(0);
union Vec3 {
	struct {
		float x, y, z; // @V0
	};

	struct {
		float r, g, b; // @Ignore
	};

	struct {
		Vec2 xy; // @Ignore
	};

	struct {
		float nothing; // @Ignore
		Vec2 yz; // @Ignore
	};

	float e[3]; // @Ignore
};

Meta_Parse_Struct(0);
union Vec3i {
	struct {
		int x, y, z; // @V0
	};

	struct {
		Vec2i xy; // @Ignore
	};

	struct {
		int nothing; // @Ignore
		Vec2i yz; // @Ignore
	};

	float e[3]; // @Ignore
};

Meta_Parse_Struct(0);
union Vec4 {
	struct {
		float x, y, z, w; // @V0
	};

	struct {
		Vec2 xy; // @Ignore
		Vec2 zw; // @Ignore
	};

	struct {
		Vec3 xyz; // @Ignore
		float w; // @Ignore
	};

	struct {
		float r, g, b, a; // @Ignore
	};

	struct {
		Vec3 rgb; // @Ignore
		float a; // @Ignore
	};

	float e[4]; // @Ignore
};

Meta_Parse_Struct(0);
union Mat4 {
	struct {
		float xa, xb, xc, xd;
		float ya, yb, yc, yd;
		float za, zb, zc, zd;
		float wa, wb, wc, wd;
	};

	struct {
		float x1, y1, z1, w1; // @Ignore
		float x2, y2, z2, w2; // @Ignore
		float x3, y3, z3, w3; // @Ignore
		float x4, y4, z4, w4; // @Ignore
	};

	float e[16]; // @Ignore

	float e2[4][4]; // @Ignore
};

Meta_Parse_Struct(0);
union Quat {
	struct {
		float w, x, y, z; // @V0
	};

	struct {
		float nothing; // @Ignore
		Vec3 xyz; // @Ignore
	};

	float e[4]; // @Ignore
};

Meta_Parse_Struct(0);
struct XForm {
	Vec3 trans; // @V0
	Quat rot; // @V0
	Vec3 scale; // @V0
};

Meta_Parse_Struct(0);
union Line2 {
	struct {
		Vec2 a;
		Vec2 b;
	};

	Vec2 e[2]; // @Ignore
};

Meta_Parse_Struct(0);
struct Line3 {
	struct {
		Vec3 a;
		Vec3 b;
	};

	Vec3 e[2]; // @Ignore
};

Meta_Parse_Struct(0);
union Rect {
	struct {
		Vec2 min; // @Ignore
		Vec2 max; // @Ignore
	};

	struct {
		Vec2 center; // @Ignore
		Vec2 dimension; // @Ignore
	};

	struct {
		float left; // @V0
		float bottom; // @V0
		float right; // @V0
		float top; // @V0
	};

	float e[4]; // @Ignore

	float w  ();
	float h  ();
	float cx ();
	float cy ();
	Vec2  dim();
	Vec2  c  ();
	Vec2  bl ();
	Vec2  l  ();
	Vec2  tl ();
	Vec2  t  ();
	Vec2  tr ();
	Vec2  r  ();
	Vec2  br ();
	Vec2  b  ();

	Rect setC   (Vec2 p);
	Rect setDim (Vec2 d);
	Rect setW   (float p);
	Rect setH   (float p);
	Rect setBL  (Vec2 p);
	Rect setTL  (Vec2 p);
	Rect setTR  (Vec2 p);
	Rect setBR  (Vec2 p);
	Rect setL   (float p);
	Rect setT   (float p);
	Rect setR   (float p);
	Rect setB   (float p);
	Rect rSetL  (float p);
	Rect rSetT  (float p);
	Rect rSetR  (float p);
	Rect rSetB  (float p);
	Rect expand (Vec2 dim);
	Rect expand (float s);
	Rect trans  (Vec2 off);
	Rect addBL  (Vec2 p);
	Rect addTL  (Vec2 p);
	Rect addTR  (Vec2 p);
	Rect addBR  (Vec2 p);
	Rect addL   (float p);
	Rect addT   (float p);
	Rect addR   (float p);
	Rect addB   (float p);

	Rect expand (float l, float b, float r, float t);

	Rect cenDim();
	Rect minMax();

	bool empty();
	bool zero();
};

Meta_Parse_Struct(0);
union Recti {
	struct {
		Vec2i min; // @Ignore
		Vec2i max; // @Ignore
	};

	struct {
		Vec2i center; // @Ignore
		Vec2i dimension; // @Ignore
	};

	struct {
		int left; // @V0
		int bottom; // @V0
		int right; // @V0
		int top; // @V0
	};

	int e[4]; // @Ignore

	float w  ();
	float h  ();
	float cx ();
	float cy ();
	Vec2i dim();
	Vec2i c  ();
};

Meta_Parse_Struct(0);
union Rect3 {
	struct {
		Vec3 min; // @V0
		Vec3 max; // @V0
	};

	struct {
		Vec3 center; // @Ignore
		Vec3 dimension; // @Ignore
	};

	float e[6]; // @Ignore

	Vec3  dim();
	Vec3  c  ();
};

Meta_Parse_Struct(0);
union Rect3i {
	struct {
		Vec3i min; // @V0
		Vec3i max; // @V0
	};

	struct {
		Vec3i center; // @Ignore
		Vec3i dimension; // @Ignore
	};

	float e[6]; // @Ignore

};

//

inline int randomInt(int from, int to) {
	return pcg32_boundedrand(to - from + 1) + from;
}

inline float randomInt01() {
	return randomInt(0,1);
}

inline float randomFloat(float from, float to) {
	return randomInt(from/0.000001f, to/0.000001f) * 0.000001f;
}

inline float randomFloat01() {
	return randomFloat(0,1);
}

inline float randomOffset(float offset) {
	return randomFloat(-offset, offset);
}

//
// @Vec2
//

inline Vec2 vec2(float a, float b) { return {a, b}; };
inline Vec2 vec2(float a) { return {a, a}; };

inline Vec2 vec2(Vec2i a) { return {(float)a.x, (float)a.y}; }
inline Vec2 vec2(Vec3 a) { return {a.x, a.y}; }

inline Vec2 operator*(Vec2 a, float b) { return {a.x*b, a.y*b}; };
inline Vec2 operator*(float b, Vec2 a) { return {a.x*b, a.y*b}; };
inline Vec2 operator*(Vec2 a, Vec2 b) { return {a.x*b.x, a.y*b.y}; };
inline Vec2 & operator*=(Vec2& a, Vec2 b) { return a = a * b; };
inline Vec2 & operator*=(Vec2& a, float b) { return a = a * b; };

inline Vec2 operator+(Vec2 a, float b) { return {a.x+b, a.y+b}; };
inline Vec2 operator+(Vec2 a, Vec2 b) { return {a.x+b.x, a.y+b.y}; };
inline Vec2 & operator+=(Vec2& a, Vec2 b) { return a = a + b; };
inline Vec2 & operator+=(Vec2& a, float b) { return a = a + b; };

inline Vec2 operator-(Vec2 a) { return {-a.x, -a.y}; };
inline Vec2 operator-(Vec2 a, float b) { return {a.x-b, a.y-b}; };
inline Vec2 operator-(Vec2 a, Vec2 b) { return {a.x-b.x, a.y-b.y}; };
inline Vec2 & operator-=(Vec2& a, Vec2 b) { return a = a - b; };
inline Vec2 & operator-=(Vec2& a, float b) { return a = a - b; };

inline Vec2 operator/(Vec2 a, float b) { return {a.x/b, a.y/b}; };
inline Vec2 operator/(float b, Vec2 a) { return {b/a.x, b/a.y}; };
inline Vec2 operator/(Vec2 a, Vec2 b) { return {a.x/b.x, a.y/b.y}; };
inline Vec2 & operator/=(Vec2& a, Vec2 b) { return a = a / b; };
inline Vec2 & operator/=(Vec2& a, float b) { return a = a / b; };

inline bool operator==(Vec2 a, Vec2 b) { return (a.x == b.x) && (a.y == b.y); };
inline bool operator!=(Vec2 a, Vec2 b) { return !(a==b); };
inline bool operator<(Vec2 a, Vec2 b) { return (a.x<b.x)&&(a.y<b.y); }
inline bool operator>(Vec2 a, Vec2 b) { return (a.x>b.x)&&(a.y>b.y); }

inline Vec2 operator+(Vec2 a, Vec2i b) { return {a.x+b.x, a.y+b.y}; }

//

inline float dot(Vec2 a, Vec2 b) { return a.x*b.x + a.y*b.y; }
inline float dot(Vec2 a) { return dot(a,a); }
inline float len(Vec2 a) { return sqrt(dot(a)); };
inline float cross(Vec2 a, Vec2 b) { return a.x*b.y - a.y*b.x; };
inline Vec2 norm(Vec2 a) { return a/len(a); };
inline float determinant(Vec2 a, Vec2 b) { return cross(norm(a), norm(b)); }

inline float dotUnitToPercent(float dotProduct) { return 1 - acos(dotProduct)/M_PI_2; }

//

inline Vec2 clampMin(Vec2 v, Vec2 d) { return {max(v.x, d.x), max(v.y, d.y)}; }
inline Vec2 clampMax(Vec2 v, Vec2 d) { return {min(v.x, d.x), min(v.y, d.y)}; }
inline Vec2 clamp(Vec2 v, Rect r)    { return {clamp(v.x, r.left, r.right), 
	                                            clamp(v.y, r.bottom, r.top)}; }
inline void clamp(Vec2* v, Rect r) { *v = clamp(*v, r); };

float mapRange(float v, Vec2 d, Vec2 r) { return mapRange(v, d.x, d.y, r.x, r.y); };
float mapRangeClamp(float v, Vec2 d, Vec2 r) { return mapRangeClamp(v, d.x, d.y, r.x, r.y); };
inline Vec2 mapRange(Vec2 a, Vec2 oldMin, Vec2 oldMax, Vec2 newMin, Vec2 newMax) {
	return {mapRange(a.x, oldMin.x, oldMax.x, newMin.x, newMax.x),
			mapRange(a.y, oldMin.y, oldMax.y, newMin.y, newMax.y)}; }

inline Vec2 lerp(float percent, Vec2 min, Vec2 max) {
	Vec2 result;
	result.x = lerp(percent, min.x, max.x);
	result.y = lerp(percent, min.y, max.y);
	return result;
}

inline Vec2 round(Vec2 a) { return {roundf(a.x), roundf(a.y)}; }

//

inline Vec2 rotateRight(Vec2 dir) { return vec2(dir.y, -dir.x); }
inline Vec2 rotateLeft(Vec2 dir) { return vec2(-dir.y, dir.x); }
inline float angleDirVec2(Vec2 dir) { return atan2(dir.y, dir.x); }
inline Vec2 angleToDir(float radians) { return vec2(cos(radians), sin(radians)); }

Vec2 rotate(Vec2 a, float radian) {
	// clockwise

	float cs = cos(-radian);
	float sn = sin(-radian);

	float nx = a.x * cs - a.y * sn;
	float ny = a.x * sn + a.y * cs;

	return vec2(nx, ny);
}

inline float angleVec2(Vec2 dir1, Vec2 dir2) {
	float dt = dot(norm(dir1), norm(dir2));
	dt = clamp(dt, -1.0f, 1.0f);
	float angle = acos(dt);
	return angle;
}

Vec2 fitDim(Vec2 srcDim, Vec2 dstDim, bool fill = true) {
	Vec2 filledDim;

	float srcAspect = srcDim.w / srcDim.h;
	float dstAspect = dstDim.w / dstDim.h;
	bool scaleWidth = !fill ? srcAspect < dstAspect : srcAspect > dstAspect;

	if(scaleWidth) {
		filledDim.w = srcDim.w;
		filledDim.h = dstDim.h * (srcDim.w / dstDim.w);
	} else {
		filledDim.h = srcDim.h;
		filledDim.w = dstDim.w * (srcDim.h / dstDim.h);
	}

	return filledDim;
}

//

inline float lenLine(Vec2 p0, Vec2 p1) { return len(p1 - p0); }

inline Vec2 lineMidPoint(Vec2 p1, Vec2 p2) {
	float x = (p1.x + p2.x)/2;
	float y = (p1.y + p2.y)/2;
	Vec2 midPoint = vec2(x,y);

	return midPoint;
}

inline int lineSide(Vec2 p1, Vec2 p2, Vec2 point) {
	int side = sign( (p2.x-p1.x)*(point.y-p1.y) - (p2.y-p1.y)*(point.x-p1.x) );
	return side;
}

inline Vec2 midOfTwoVectors(Vec2 p0, Vec2 p1, Vec2 p2) {
	Vec2 dir1 = norm(p0 - p1);
	Vec2 dir2 = norm(p2 - p1);
	Vec2 mid = lineMidPoint(dir1, dir2);
	mid = norm(mid);
	return mid;
}

inline Vec2 lineNormal(Vec2 p1, Vec2 p2) {
	float dx = p2.x - p1.x;
	float dy = p2.y - p1.y;
	Vec2 normal = vec2(-dy,dx); // or (dy,-dx)
	normal = norm(normal);

	return normal;
}

inline bool getLineIntersection(Vec2 p0, Vec2 p1, Vec2 p2, Vec2 p3, Vec2* i) {
	Vec2 s1 = p1 - p0;
	Vec2 s2 = p3 - p2;

	float s, t;

	float div = (-s2.x * s1.y + s1.x * s2.y);

	s = (-s1.y * (p0.x - p2.x) + s1.x * (p0.y - p2.y)) / div;
	t = ( s2.x * (p0.y - p2.y) - s2.y * (p0.x - p2.x)) / div;

	if (s >= 0 && s <= 1 && t >= 0 && t <= 1) {
		*i = p0 + t*s1;
		return true;
	}

	return false;
}

inline bool getLineIntersectionInf(Vec2 p0, Vec2 d0, Vec2 p1, Vec2 d1, Vec2* i) {
	float s, t;
	float div = (-d1.x * d0.y + d0.x * d1.y);
	if(!div) return false;

	s = (-d0.y * (p0.x - p1.x) + d0.x * (p0.y - p1.y)) / div;
	t = ( d1.x * (p0.y - p1.y) - d1.y * (p0.x - p1.x)) / div;

	*i = p0 + t*d0;
	return true;
}

float distancePointLineX(Vec2 v1, Vec2 v2, Vec2 point, bool infinite = false) {
	Vec2 diff = v2 - v1;
    if (diff == vec2(0,0))
    {
    	diff = point - v1;
        return len(diff);
    }

    float t = ((point.x - v1.x) * diff.x + (point.y - v1.y) * diff.y) / 
    		   (diff.x * diff.x + diff.y * diff.y);

   	if(infinite) {
		diff = point - (v1 + t*diff);
   	} else {
	    if 		(t < 0) diff = point - v1;
	    else if (t > 1) diff = point - v2;
	    else 			diff = point - (v1 + t*diff);
   	}

    return len(diff);
}


Vec2 lineClosestPoint(Vec2 v1, Vec2 v2, Vec2 point, bool segment = true) {
	Vec2 result;

	Vec2 dir = v2 - v1;
	if (dir.x == 0.0f && dir.y == 0.0f) result = v1;
	else {
		float t = ((point.x - v1.x) * dir.x + (point.y - v1.y) * dir.y) / 
		          (dir.x * dir.x + dir.y * dir.y);

		if(segment) {
			if      (t < 0) result = v1;
			else if (t > 1) result = v2;
			else result = v1 + t*dir;
		} else {
			result = v1 + t*dir;
		}
	}

	return result;
}

float distancePointLine(Vec2 v1, Vec2 v2, Vec2 point) {
	Vec2 cp = lineClosestPoint(v1, v2, point);

	float dist = len(cp - point);
	return dist;
}

Vec2 projectPointOnLine(Vec2 p, Vec2 lp0, Vec2 lp1, bool clampDist = false) {
	Vec2 ld = norm(lp1 - lp0);
	float dist = (dot(p-lp0, ld) / dot(ld, ld));

	if(clampDist) dist = clamp(dist, 0.0f, len(lp1 - lp0));

	Vec2 result = lp0 + ld * dist;

	return result;
}

float sign(Vec2 p1, Vec2 p2, Vec2 p3) {
	return (p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y);
}

bool pointInTriangle(Vec2 pt, Vec2 v1, Vec2 v2, Vec2 v3) {
	bool b1, b2, b3;

	b1 = sign(pt, v1, v2) < 0.0f;
	b2 = sign(pt, v2, v3) < 0.0f;
	b3 = sign(pt, v3, v1) < 0.0f;

	return ((b1 == b2) && (b2 == b3));
}

Vec2 closestPointToTriangle(Vec2 p, Vec2 a, Vec2 b, Vec2 c) {
	bool insideTriangle = pointInTriangle(p, a, b, c);
	if(insideTriangle) return p;

	Vec2 p0 = projectPointOnLine(p, a, b, true);
	Vec2 p1 = projectPointOnLine(p, b, c, true);
	Vec2 p2 = projectPointOnLine(p, c, a, true);

	float d0 = len(p0 - p);
	float d1 = len(p1 - p);
	float d2 = len(p2 - p);

	float shortestDist = min(d0, d1, d2);

	Vec2 closestPoint = vec2(0,0);
	     if(shortestDist == d0) closestPoint = p0;
	else if(shortestDist == d1) closestPoint = p1;
	else if(shortestDist == d2) closestPoint = p2;

	return closestPoint;
}

inline bool lineCircleIntersection(Vec2 lp0, Vec2 lp1, Vec2 cp, float r, Vec2 * i) {
	Vec2 d = lp1 - lp0;
	Vec2 f = lp0 - cp;

	float a = dot(d,d);
	float b = 2*dot(f,d);
	float c = dot(f,f) - r*r;

	float discriminant = b*b-4*a*c;
	if( discriminant < 0 )
	{
		return false;
	}
	else
	{
		discriminant = sqrt( discriminant );

		float t1 = (-b - discriminant)/(2*a);
		float t2 = (-b + discriminant)/(2*a);

		if( t1 >= 0 && t1 <= 1 )
		{
			*i = lp0 + d*t1;
			return true;
		}

		if( t2 >= 0 && t2 <= 1 )
		{
			*i = lp0 + d*t2;
			return true;
		}

		return false;
	}

	return false;
}

float floatPrecisionOffset(float f, int scale, float min) {
	float next = f;
	for (int i = 0; i < scale; i++)
		next = nextafterf(next, FLT_MAX);
	
	float offset = max(next - f, min);
	return offset;
}

float floatPrecisionOffset(Vec2 a, Vec2 b, int scale, float min) {
	return floatPrecisionOffset(max(max(a.x, a.y), max(b.x, b.y)), scale, min);
}

//

float ellipseDistanceCenterEdge(float width, float height, Vec2 dir) {
	// dir has to be normalized
	float dirOverWidth = dir.x/width;
	float dirOverHeight = dir.y/height;
	float length = sqrt(1 / (dirOverWidth*dirOverWidth + dirOverHeight*dirOverHeight));
	return length;
}

bool ellipseGetLineIntersection(float a, float b, float h, float k, Vec2 p0, Vec2 p1, Vec2 &i1, Vec2 &i2) {
	// y = mx + c
	float m;
	if(p1.x-p0.x == 0) m = 1000000;
	// if(p1.x-p0.x == 0) m = 0.00001f;
	else m = (p1.y-p0.y)/(p1.x-p0.x);
	float c = p0.y - m*p0.x;

	float aa = a*a;
	float bb = b*b;
	float mm = m*m;
	float temp1 = c + m*h;
	float d = aa*mm + bb - pow(temp1,2) - k*k + 2*temp1*k;

	if (d < 0)
	{
		return false;
	}
	else
	{
		Vec2 inter1;
		Vec2 inter2;
		float q = aa*mm + bb;
		float r = h*bb - m*aa*(c-k);
		float s = bb*temp1 + k*aa*mm;

		float u = a*b*sqrt(d);
		inter1.x = (r - u) / q;
		inter2.x = (r + u) / q;

		float v = a*b*m*sqrt(d);
		inter1.y = (s - v) / q;
		inter2.y = (s + v) / q;

		float lLine = len(p1 - p0);
		float lp0 = len(inter1 - p0);
		float lp1 = len(inter2 - p0);
		if(lp0 <= lp1) {
			i1 = inter1;
			i2 = inter2;
		} else {
			i1 = inter2;
			i2 = inter1;			
		}
		if(len(i1 - p0) > lLine) return false;
		// if(lp0 > lLine) return false;

		return true;
	}

	return false;
}

Vec2 ellipseNormal(Vec2 pos, float width, float height, Vec2 point) {
	Vec2 dir = vec2((point.x-pos.x)/pow(width,2), (point.y-pos.y)/pow(height,2));
	dir = -norm(dir);
	return dir;
}

float polygonArea(Vec2* polygon, int count) {
	float signedArea = 0;
	for(int i = 0; i < count; i++) {
		int secondIndex = i+1;
		if(i == count-1) secondIndex = 0;
		Vec2 p1 = polygon[i];
		Vec2 p2 = polygon[secondIndex];

		signedArea += (p1.x * p2.y - p2.x * p1.y);
	}

	return signedArea / 2;
}

//

inline Vec2 calculatePosition(Vec2 oldPosition, Vec2 velocity, Vec2 acceleration, float time) {
	oldPosition += 0.5f*acceleration*time*time + velocity*time;
	return oldPosition;
}

inline Vec2 calculateVelocity(Vec2 oldVelocity, Vec2 acceleration, float time) {
	oldVelocity += acceleration*time;
	return oldVelocity;
}

inline Vec2 perpToPoint(Vec2 ab, Vec2 ac) {
	// Vec3 ab = { dir.x, dir.y, 0 };
	// Vec3 ap = { dirPoint.x, dirPoint.y, 0 };

	// Vec3 abxap = {	ab.y*ap.z - ab.z*ap.y,
	//                ab.z*ap.x - ab.x*ap.z,
	//                ab.x*ap.y - ab.y*ap.x };

	// Vec3 xab = { abxap.y*ab.z - abxap.z*ab.y,
	// 				 abxap.z*ab.x - abxap.x*ab.z,
	// 				 abxap.x*ab.y - abxap.y*ab.x };

	float abxac = ac.x*ab.y - ac.y*ab.x;              
	Vec2 xab = { -abxac*ab.y, abxac*ab.x };

	return xab;
}

inline bool vecBetweenVecs(Vec2 v, Vec2 left, Vec2 right) {
	bool result;
	float ca = cross(left,v);
	float cb = cross(right,v);

	result = ca < 0 && cb > 0;
	return result;
}

Vec2 circumcenter(Vec2 a, Vec2 b, Vec2 c) {
	float x = c.y*(pow(b.x,2) + pow(b.y,2)) - b.y*(pow(c.x,2) + pow(c.y,2));
	float y = b.x*(pow(c.x,2) + pow(c.y,2)) - c.x*(pow(b.x,2) + pow(b.y,2));
	float d = 2*(b.x*c.y - b.y*c.x);
	x = x / d;
	y = y / d;

	Vec2 center = vec2(x,y);
	return center;
}

//
// @Vec2i
//

inline Vec2i vec2i(int a, int b) { return {a, b}; };
inline Vec2i vec2i(int a) { return {a, a}; };

inline Vec2i vec2i(Vec2 a) { return {(int)a.x, (int)a.y}; }

inline Vec2i operator*(Vec2i a, int b) { return {a.x*b, a.y*b}; };
inline Vec2i operator*(int b, Vec2i a) { return {a.x*b, a.y*b}; };
inline Vec2i operator*(Vec2i a, Vec2i b) { return {a.x*b.x, a.y*b.y}; };
inline Vec2i & operator*=(Vec2i& a, Vec2i b) { return a = a * b; };
inline Vec2i & operator*=(Vec2i& a, int b) { return a = a * b; };

inline Vec2i operator+(Vec2i a, int b) { return {a.x+b, a.y+b}; };
inline Vec2i operator+(Vec2i a, Vec2i b) { return {a.x+b.x, a.y+b.y}; };
inline Vec2i & operator+=(Vec2i& a, Vec2i b) { return a = a + b; };
inline Vec2i & operator+=(Vec2i& a, int b) { return a = a + b; };

inline Vec2i operator-(Vec2i a) { return {-a.x, -a.y}; };
inline Vec2i operator-(Vec2i a, int b) { return {a.x-b, a.y-b}; };
inline Vec2i operator-(Vec2i a, Vec2i b) { return {a.x-b.x, a.y-b.y}; };
inline Vec2i & operator-=(Vec2i& a, Vec2i b) { return a = a - b; };
inline Vec2i & operator-=(Vec2i& a, int b) { return a = a - b; };

inline Vec2i operator/(Vec2i a, int b) { return {a.x/b, a.y/b}; };
inline Vec2i operator/(Vec2i a, Vec2i b) { return {a.x/b.x, a.y/b.y}; };
inline Vec2i & operator/=(Vec2i& a, Vec2i b) { return a = a / b; };
inline Vec2i & operator/=(Vec2i& a, int b) { return a = a / b; };

inline bool operator==(Vec2i a, Vec2i b) { return (a.x == b.x) && (a.y == b.y); };
inline bool operator!=(Vec2i a, Vec2i b) { return !(a==b); };

//

inline Vec2i clampMin(Vec2i v, Vec2i d) { return {max(v.x, d.x), max(v.y, d.y)}; }
inline Vec2i clampMax(Vec2i v, Vec2i d) { return {min(v.x, d.x), min(v.y, d.y)}; }
inline Vec2i clamp(Vec2i v, Recti r) { return {clamp(v.x, r.left, r.right), 
	                                            clamp(v.y, r.bottom, r.top)}; }
inline void clamp(Vec2i* v, Recti r) { *v = clamp(*v, r); };

//
// @Vec3
//

inline Vec3 vec3(float a, float b, float c) { return {a, b, c}; };
inline Vec3 vec3(float a) { return {a, a, a}; };

inline Vec3 vec3(float a[3]) { return {a[0], a[1], a[2]}; }
inline Vec3 vec3(Vec3i a) { return {(float)a.x, (float)a.y, (float)a.z}; }
inline Vec3 vec3(Vec2 a) { return {a.x, a.y, 0}; }
inline Vec3 vec3(Vec2 a, float b) { return {a.x, a.y, b}; }
inline Vec3 vec3(float b, Vec2 a) { return {b, a.x, a.y}; }

inline Vec3 operator*(Vec3 a, float b) { return {a.x*b, a.y*b, a.z*b}; };
inline Vec3 operator*(float b, Vec3 a) { return {a.x*b, a.y*b, a.z*b}; };
inline Vec3 operator*(Vec3 a, Vec3 b) { return {a.x*b.x, a.y*b.y, a.z*b.z}; };
inline Vec3 & operator*=(Vec3& a, Vec3 b) { return a = a * b; };
inline Vec3 & operator*=(Vec3& a, float b) { return a = a * b; };

inline Vec3 operator+(Vec3 a) { return a; };
inline Vec3 operator+(Vec3 a, float b) { return {a.x+b, a.y+b, a.z+b}; };
inline Vec3 operator+(Vec3 a, Vec3 b) { return {a.x+b.x, a.y+b.y, a.z+b.z}; };
inline Vec3 & operator+=(Vec3& a, Vec3 b) { return a = a + b; };
inline Vec3 & operator+=(Vec3& a, float b) { return a = a + b; };

inline Vec3 operator-(Vec3 a) { return {-a.x, -a.y, -a.z}; };
inline Vec3 operator-(Vec3 a, float b) { return {a.x-b, a.y-b, a.z-b}; };
inline Vec3 operator-(Vec3 a, Vec3 b) { return {a.x-b.x, a.y-b.y, a.z-b.z}; };
inline Vec3 & operator-=(Vec3& a, Vec3 b) { return a = a - b; };
inline Vec3 & operator-=(Vec3& a, float b) { return a = a - b; };

inline Vec3 operator/(Vec3 a, float b) { return {a.x/b, a.y/b, a.z/b}; };
inline Vec3 operator/(float b, Vec3 a) { return {b/a.x, b/a.y, b/a.z}; };
inline Vec3 operator/(Vec3 a, Vec3 b) { return {a.x/b.x, a.y/b.y, a.z/b.z}; };
inline Vec3 & operator/=(Vec3& a, Vec3 b) { return a = a / b; };
inline Vec3 & operator/=(Vec3& a, float b) { return a = a / b; };

inline bool operator==(Vec3 a, Vec3 b) { return (a.x==b.x) && (a.y==b.y) && (a.z==b.z); };
inline bool operator!=(Vec3 a, Vec3 b) { return !(a==b); };

//

inline float dot(Vec3 a, Vec3 b) { return a.x*b.x + a.y*b.y + a.z*b.z; }
inline float dot(Vec3 a) { return dot(a,a); }
inline float len(Vec3 a) { return sqrt(dot(a)); };
inline float lenSquared(Vec3 a) { return dot(a); };
inline Vec3 cross(Vec3 a, Vec3 b) { return {a.y*b.z-a.z*b.y, a.z*b.x-a.x*b.z, 
	                                        a.x*b.y-a.y*b.x}; }
inline Vec3 norm(Vec3 a) { return a/len(a); };

inline Vec3 clamp(Vec3 a) { 
	return { min(max(a.x, 0.0f), 1.0f), min(max(a.y, 0.0f), 1.0f), 
	         min(max(a.z, 0.0f), 1.0f),  }; 
};

Vec3 lerp(float percent, Vec3 a, Vec3 b) {
	a.x = lerp(percent, a.x, b.x);
	a.y = lerp(percent, a.y, b.y);
	a.z = lerp(percent, a.z, b.z);

	return a;
}

Vec3 min(Vec3 a, Vec3 b) {
	a.x = min(a.x, b.x);
	a.y = min(a.y, b.y);
	a.z = min(a.z, b.z);

	return a;
}

Vec3 max(Vec3 a, Vec3 b) {
	a.x = max(a.x, b.x);
	a.y = max(a.y, b.y);
	a.z = max(a.z, b.z);

	return a;
}

Vec3 getRotationToVector(Vec3 start, Vec3 dest, float* angle) {
	Vec3 side = norm(cross(start, norm(dest)));
	*angle = dot(start, norm(dest));
	*angle = acos(*angle)*2;

	return side;
}	

//

Vec3 projectPointOnLine(Vec3 lPos, Vec3 lDir, Vec3 p) {
	Vec3 result;
	result = lPos + ((dot(p-lPos, lDir) / dot(lDir,lDir))) * lDir;
	return result;
}

// Copyright 2001 softSurfer, 2012 Dan Sunday
Vec3 lineClosestPoint(Vec3 p0, Vec3 d0, Vec3 p1, Vec3 d1) {
    Vec3  u = d0;
    Vec3  v = d1;
    Vec3  w = p0 - p1;
    float a = dot(u,u);         // always >= 0
    float b = dot(u,v);
    float c = dot(v,v);         // always >= 0
    float d = dot(u,w);
    float e = dot(v,w);
    float D = a*c - b*b;        // always >= 0
    float sc, tc;

    const double SMALL_NUM = 0.00000001; // anything that avoids division overflow

    // compute the line parameters of the two closest points
    if (D < SMALL_NUM) {          // the lines are almost parallel
        sc = 0.0;
        tc = (b>c ? d/b : e/c);    // use the largest denominator
    } else {
        sc = (b*e - c*d) / D;
        tc = (a*e - b*d) / D;
    }

    Vec3 pointA = p0 + sc * u;
    Vec3 pointB = p1 + tc * v;

    Vec3 mid = (pointA + pointB)/2.0f;

    return mid;
}

int getBiggestAxis(Vec3 v, int smallerAxis[2] = 0) {
	float values[3] = {fabs(v.x), fabs(v.y), fabs(v.z)};
	float maximum = max(values[0], values[1], values[2]);
	int biggestAxis;
	if(values[0] == maximum) biggestAxis = 0;
	else if(values[1] == maximum) biggestAxis = 1;
	else biggestAxis = 2;

	if(smallerAxis != 0) {
		int axis1 = mod(biggestAxis-1, 3);
		int axis2 = mod(biggestAxis+1, 3);
		smallerAxis[0] = v.e[biggestAxis] < 0 ? axis1 : axis2;
		smallerAxis[1] = v.e[biggestAxis] < 0 ? axis2 : axis1;
	}

	return biggestAxis;
}

inline Vec3 reflectVector(Vec3 dir, Vec3 normal) {
	Vec3 result = dir - 2*(dot(dir, normal))*normal;
	return result;
}

Vec3 randomBoxPoint(Vec3 dim) {
	return vec3(randomOffset(dim.x), randomOffset(dim.y), randomOffset(dim.z));
}

Vec3 randomDiskPoint() {
	// Distribute in rect and discard if not in disk.

	Vec3 p;
	do {
		p = vec3(randomOffset(1), randomOffset(1), 0);
	} while(len(p.xy) > 1);

	return p;
}

Vec3 randomSpherePoint() {
	// Distribute in box and discard if not in sphere.

	Vec3 p;
	do {
		p = vec3(randomOffset(1), randomOffset(1), randomOffset(1));
	} while(len(p) > 1);

	return p;
}

Vec3 randomUnitSphereDirection() {
	return norm(randomSpherePoint());
}

Vec3 randomUnitHalfSphereDirection(Vec3 dir) {
	Vec3 p = randomUnitSphereDirection();
	if(dot(dir, p) < 0) p = reflectVector(p, dir);

	return p;
}

Vec3 circumcenter(Vec3 a, Vec3 b, Vec3 c) {

	// This has been changed and is not tested.

	//		  |c-a|^2 [(b-a)x(c-a)]x(b-a) + |b-a|^2 (c-a)x[(b-a)x(c-a)]
	//m = a + ---------------------------------------------------------.
	//						    2 | (b-a)x(c-a) |^2

	//Vector3f a,b,c // are the 3 pts of the tri

	Vec3 ac = c - a;
	Vec3 ab = b - a;
	Vec3 abXac = cross(ab, ac);

	// this is the vector from a TO the circumsphere center

	Vec3 t1, t2;

	t1 = cross(abXac, ab);
	t2 = cross(ac, abXac);
	t1 *= pow(len(ac),2);
	t1 *= pow(len(ab),2);

	t1 += t2;
	t1 *= 1.0f/(pow(len(abXac),2) * 2);

	// The 3 space coords of the circumsphere center then:

	Vec3 toCircumsphereCenter = t1;
	Vec3 center = a + toCircumsphereCenter;
	return center;
}

void getPointsFromQuadAndNormal(Vec3 p, Vec3 normal, float size, Vec3 verts[4]) {
	int sAxis[2];
	int biggestAxis = getBiggestAxis(normal, sAxis);

	float s2 = size*0.5f;

	for(int i = 0; i < 4; i++) {
		Vec3 d = p;
		if(i == 0) { d.e[sAxis[0]] += -s2; d.e[sAxis[1]] += -s2; }
		else if(i == 1) { d.e[sAxis[0]] += -s2; d.e[sAxis[1]] +=  s2; }
		else if(i == 2) { d.e[sAxis[0]] +=  s2; d.e[sAxis[1]] +=  s2; }
		else if(i == 3) { d.e[sAxis[0]] +=  s2; d.e[sAxis[1]] += -s2; }
		verts[i] = d;
	}
}

inline bool boxIntersection(Vec3 b1, Vec3 d1, Vec3 b2, Vec3 d2) {
	Vec3 min1 = b1 - d1/2.0f;
	Vec3 max1 = b1 + d1/2.0f;
	Vec3 min2 = b2 - d2/2.0f;
	Vec3 max2 = b2 + d2/2.0f;

	bool result = !( min2.x > max1.x ||
					 max2.x < min1.x ||
					 max2.y < min1.y ||
					 min2.y > max1.y ||
					 max2.z < min1.z ||
					 min2.z > max1.z);
	return result;
}

Vec3 boxNormals[6] = {vec3(-1,0,0), vec3(1,0,0), vec3(0,-1,0), vec3(0,1,0), vec3(0,0,-1), vec3(0,0,1)};
float lineBoxIntersection(Vec3 lp, Vec3 ld, Vec3 boxPos, Vec3 boxDim, Vec3* intersection = 0, Vec3* intersectionNormal = 0, bool secondIntersection = false) {

	Vec3 boxHalfDim = boxDim/2;
	Vec3 boxMin = boxPos - boxHalfDim;
	Vec3 boxMax = boxPos + boxHalfDim;

	// ld is unit
	Vec3 dirfrac = 1.0f / ld;
	// lb is the corner of AABB with minimal coordinates - left bottom, rt is maximal corner
	// r.org is origin of ray
	float t1 = (boxMin.x - lp.x)*dirfrac.x;
	float t2 = (boxMax.x - lp.x)*dirfrac.x;
	float t3 = (boxMin.y - lp.y)*dirfrac.y;
	float t4 = (boxMax.y - lp.y)*dirfrac.y;
	float t5 = (boxMin.z - lp.z)*dirfrac.z;
	float t6 = (boxMax.z - lp.z)*dirfrac.z;

	float tmin = max(max(min(t1, t2), min(t3, t4)), min(t5, t6));
	float tmax = min(min(max(t1, t2), max(t3, t4)), max(t5, t6));

	// if tmax < 0, ray (line) is intersecting AABB, but whole AABB is behind us
	if (tmax < 0) return -1;

	// if tmin > tmax, ray doesn't intersect AABB
	if (tmin > tmax) return -1;

	float distance = secondIntersection ? tmax : tmin;
	if(distance < 0) return -1;

	if(intersection) *intersection = lp + ld*distance;

	if(intersectionNormal) {
		     if(distance == t1) *intersectionNormal = boxNormals[0];
		else if(distance == t2) *intersectionNormal = boxNormals[1];
		else if(distance == t3) *intersectionNormal = boxNormals[2];
		else if(distance == t4) *intersectionNormal = boxNormals[3];
		else if(distance == t5) *intersectionNormal = boxNormals[4];
		else if(distance == t6) *intersectionNormal = boxNormals[5];
	}

	return distance;
}

Vec3 projectPointOnPlane(Vec3 p, Vec3 planePos, Vec3 planeNormal) {
	p = p - planePos;
	p = p - planeNormal * dot(planeNormal, p);
	p = p + planePos;

	return p;
}

// https://gamedev.stackexchange.com/questions/23743/whats-the-most-efficient-way-to-find-barycentric-coordinates
Vec3 barycentricCoordinates(Vec3 p, Vec3 a, Vec3 b, Vec3 c) {
    Vec3 v0 = b - a, v1 = c - a, v2 = p - a;
    float d00 = dot(v0, v0);
    float d01 = dot(v0, v1);
    float d11 = dot(v1, v1);
    float d20 = dot(v2, v0);
    float d21 = dot(v2, v1);
    float denom = d00 * d11 - d01 * d01;
    float v = (d11 * d20 - d01 * d21) / denom;
    float w = (d00 * d21 - d01 * d20) / denom;
    float u = 1.0f - v - w;

    return {u, v, w};
}

// https://gamedev.stackexchange.com/questions/23743/whats-the-most-efficient-way-to-find-barycentric-coordinates
Vec3 barycentricCoordinates(Vec2 p, Vec2 a, Vec2 b, Vec2 c) {
    Vec2 v0 = b - a, v1 = c - a, v2 = p - a;
    float d00 = dot(v0, v0);
    float d01 = dot(v0, v1);
    float d11 = dot(v1, v1);
    float d20 = dot(v2, v0);
    float d21 = dot(v2, v1);
    float denom = d00 * d11 - d01 * d01;
    float v = (d11 * d20 - d01 * d21) / denom;
    float w = (d00 * d21 - d01 * d20) / denom;
    float u = 1.0f - v - w;

    return {u, v, w};
}

// https://en.wikipedia.org/wiki/M%C3%B6ller%E2%80%93Trumbore_intersection_algorithm
inline bool lineTriangleIntersection(Vec3 lp, Vec3 ld, Vec3 tp0, Vec3 tp1, Vec3 tp2, Vec3* intersection = 0, bool ignoreBackface = false) {

	const float EPSILON = 0.0000001;

	Vec3 edge1, edge2, h, s, q;
	float a,f,u,v;
	edge1 = tp1 - tp0;
	edge2 = tp2 - tp0;
	h = cross(ld, edge2);
	a = dot(edge1, h);
	if (a > -EPSILON && a < EPSILON) return false; // This ray is parallel to this triangle.

	f = 1.0/a;
	s = lp - tp0;
	u = f * dot(s, h);
	if (u < 0.0 || u > 1.0) return false;

	q = cross(s, edge1);
	v = f * dot(ld, q);
	if (v < 0.0 || u + v > 1.0) return false;
	
	// At this stage we can compute t to find out where the intersection point is on the line.
	float t = f * dot(edge2, q);
	
	if (t > EPSILON) // ray intersection 
	{
		if(intersection) *intersection = lp + ld * t;

		Vec3 triangleNormal = cross(tp1 - tp0, tp2 - tp0);
		if(!ignoreBackface) return true;

		if(dot(triangleNormal, ld) >= 0) return true;
		else return false;
	}
	else // This means that there is a line intersection but not a ray intersection.

	return false;
}

bool lineQuadIntersection(Vec3 lp, Vec3 ld, Vec3 tp0, Vec3 tp1, Vec3 tp2, Vec3 tp3, Vec3* intersection = 0, bool ignoreBackface = false) {

	bool result;

	result = lineTriangleIntersection(lp, ld, tp0, tp1, tp2, intersection);
	if(result) return true;

	result = lineTriangleIntersection(lp, ld, tp2, tp3, tp0, intersection);
	if(result) return true;

	return false;
}

bool lineCubeIntersection(Vec3 lp, Vec3 ld, Vec3 tp0, Vec3 tp1, Vec3 tp2, Vec3 tp3, Vec3* intersection = 0, bool ignoreBackface = false) {

	bool result;

	result = lineTriangleIntersection(lp, ld, tp0, tp1, tp2, intersection);
	if(result) return true;

	result = lineTriangleIntersection(lp, ld, tp2, tp3, tp0, intersection);
	if(result) return true;

	return false;
}

float linePlaneIntersection(Vec3 lp, Vec3 ld, Vec3 pp, Vec3 pn, Vec3 pu, Vec2 dim, Vec3* intersection = 0, Vec3* intersectionNormal = 0) {
	// Assuming pu is unit vector.

	float a = dot(pn, ld);
	if(a == 0) return -1;

	float distance = -(dot(pn, lp) - dot(pn, pp)) / a;
	if(distance >= 0) {
		Vec3 ip = lp + ld*distance;
		ip = ip - pp;
		float ix = dot(ip, pu);   // ip*cos(angle)

		float lenIp = len(ip);
		float angle = acos(ix/lenIp);
		float iy = lenIp*sin(angle); // sin(angle)

		if(fabs(ix) > dim.y/2.0f || fabs(iy) > dim.x/2.0f) return -1;

		if(intersection) {
			*intersection = lp + ld*distance;
			if(intersectionNormal) *intersectionNormal = pn;
		}

		return distance;
	}

	return -1;
}

float linePlaneIntersection(Vec3 lp, Vec3 ld, Vec3 pp, Vec3 pn, Vec3* intersection = 0, Vec3* intersectionNormal = 0) {

	// N * (Q - E) = 0, t = N*(Q-E) / N*D.

	float a = dot(pn, ld);
	if(a == 0) return -1;

	float distance = dot(pn, (pp-lp)) / a;
	if(distance >= 0) {
		if(intersection) *intersection = lp + ld*distance;
		if(intersectionNormal) 
			*intersectionNormal = a < 0 ? pn : -pn;
		return distance;
	}

	return -1;
}

float lineSphereIntersection(Vec3 lp, Vec3 ld, Vec3 sp, float sr, Vec3* intersection = 0, Vec3* intersectionNormal = 0, bool secondIntersection = false) {
	// ld must be unit.

	Vec3 oldP = lp;
	lp -= sp;

	float dotLdLp = dot(ld,lp);
	float lenLp = len(lp);
	float b = dotLdLp*dotLdLp - lenLp*lenLp + sr*sr;

	if(b < 0) return -1;

	// Always choose shorter distance to get intersection that's closest.

	float distance = -(dot(ld, lp));
	if(secondIntersection) distance += sqrt(b);
	else distance += -sqrt(b);

	if(distance < 0) return -1;

	if(intersection) {
		*intersection = oldP + ld*distance;
		if(intersectionNormal) {
			(*intersectionNormal) = norm((*intersection) - sp);
		}
	}

    return distance;
}

//
// @Vec3i
//

inline Vec3i vec3i(int a, int b, int c) { return {a, b, c}; };
inline Vec3i vec3i(int a) { return {a, a, a}; };

inline Vec3i vec3i(Vec3 a) { return {(int)a.x, (int)a.y, (int)a.z}; }
inline Vec3i vec3i(Vec2i a) { return {a.x, a.y, 0}; }
inline Vec3i vec3i(Vec2i a, int b) { return {a.x, a.y, b}; }

inline Vec3i operator*(Vec3i a, int b) { return {a.x*b, a.y*b, a.z*b}; };
inline Vec3i operator*(int b, Vec3i a) { return {a.x*b, a.y*b, a.z*b}; };
inline Vec3i operator*(Vec3i a, Vec3i b) { return {a.x*b.x, a.y*b.y, a.z*b.z}; };
inline Vec3i & operator*=(Vec3i& a, Vec3i b) { return a = a * b; };
inline Vec3i & operator*=(Vec3i& a, int b) { return a = a * b; };

inline Vec3i operator+(Vec3i a, int b) { return {a.x+b, a.y+b, a.z+b}; };
inline Vec3i operator+(Vec3i a, Vec3i b) { return {a.x+b.x, a.y+b.y, a.z+b.z}; };
inline Vec3i & operator+=(Vec3i& a, Vec3i b) { return a = a + b; };
inline Vec3i & operator+=(Vec3i& a, int b) { return a = a + b; };

inline Vec3i operator-(Vec3i a) { return {-a.x, -a.y, -a.z}; };
inline Vec3i operator-(Vec3i a, int b) { return {a.x-b, a.y-b, a.z-b}; };
inline Vec3i operator-(Vec3i a, Vec3i b) { return {a.x-b.x, a.y-b.y, a.z-b.z}; };
inline Vec3i & operator-=(Vec3i& a, Vec3i b) { return a = a - b; };
inline Vec3i & operator-=(Vec3i& a, int b) { return a = a - b; };

inline Vec3i operator/(Vec3i a, int b) { return {a.x/b, a.y/b, a.z/b}; };
inline Vec3i operator/(Vec3i a, Vec3i b) { return {a.x/b.x, a.y/b.y, a.z/b.z}; };
inline Vec3i & operator/=(Vec3i& a, Vec3i b) { return a = a / b; };
inline Vec3i & operator/=(Vec3i& a, int b) { return a = a / b; };

inline bool operator==(Vec3i a, Vec3i b) { return (a.x==b.x) && (a.y==b.y) && (a.z==b.z); };
inline bool operator!=(Vec3i a, Vec3i b) { return !(a==b); };

//
// @Vec4
//

inline Vec4 vec4(float a, float b, float c, float d) { return {a, b, c, d}; }
inline Vec4 vec4(float a) { return {a, a, a, a}; };
inline Vec4 vec4(float a, float b) { return {a, a, a, b}; };

inline Vec4 vec4(Vec3 a, float b) { return {a.x, a.y, a.z, b}; }

inline Vec4 operator*(Vec4 a, float b) { return {a.x*b, a.y*b, a.z*b, a.w*b}; };
inline Vec4 operator*(float b, Vec4 a) { return {a.x*b, a.y*b, a.z*b, a.w*b}; };
inline Vec4 operator*(Vec4 a, Vec4 b) { return {a.x*b.x, a.y*b.y, a.z*b.z, a.w*b.w}; };
inline Vec4 & operator*=(Vec4& a, Vec4 b) { return a = a * b; };
inline Vec4 & operator*=(Vec4& a, float b) { return a = a * b; };

inline Vec4 operator+(Vec4 a, float b) { return {a.x+b, a.y+b, a.z+b, a.w+b}; };
inline Vec4 operator+(Vec4 a, Vec4 b) { return {a.x+b.x, a.y+b.y, a.z+b.z, a.w+b.w}; };
inline Vec4 & operator+=(Vec4& a, Vec4 b) { return a = a + b; };
inline Vec4 & operator+=(Vec4& a, float b) { return a = a + b; };

inline Vec4 operator-(Vec4 a) { return {-a.x, -a.y, -a.z, -a.w}; };
inline Vec4 operator-(Vec4 a, float b) { return {a.x-b, a.y-b, a.z-b, a.w-b}; };
inline Vec4 operator-(Vec4 a, Vec4 b) { return {a.x-b.x, a.y-b.y, a.z-b.z, a.w-b.w}; };
inline Vec4 & operator-=(Vec4& a, Vec4 b) { return a = a - b; };
inline Vec4 & operator-=(Vec4& a, float b) { return a = a - b; };

inline Vec4 operator/(Vec4 a, float b) { return {a.x/b, a.y/b, a.z/b, a.w/b}; };
inline Vec4 operator/(Vec4 a, Vec4 b) { return {a.x/b.x, a.y/b.y, a.z/b.z, a.w/b.w}; };
inline Vec4 & operator/=(Vec4& a, Vec4 b) { return a = a / b; };
inline Vec4 & operator/=(Vec4& a, float b) { return a = a / b; };

inline bool operator==(Vec4 a, Vec4 b) { return (a.x==b.x) && (a.y==b.y) && 
	                                            (a.z==b.z) && (a.w==b.w); };
inline bool operator!=(Vec4 a, Vec4 b) { return !(a==b); };

inline Vec4 clamp(Vec4 a) { 
	return { min(max(a.x, 0.0f), 1.0f), min(max(a.y, 0.0f), 1.0f), 
	         min(max(a.z, 0.0f), 1.0f), min(max(a.w, 0.0f), 1.0f) }; 
};

//
// @Mat4
//

inline Mat4 operator*(Mat4 a, Mat4 b) {
	Mat4 r;
	int i = 0;
	for(int y = 0; y < 16; y += 4) {
		for(int x = 0; x < 4; x++) {
			r.e[i++] = a.e[y]*b.e[x]     + a.e[y+1]*b.e[x+4] + 
			           a.e[y+2]*b.e[x+8] + a.e[y+3]*b.e[x+12];
		}
	}
	return r;
}

// #include <emmintrin.h>
inline Vec4 operator*(Mat4 m, Vec4 v) {
	Vec4 result;
	result.x = m.xa*v.x + m.xb*v.y + m.xc*v.z + m.xd*v.w;
	result.y = m.ya*v.x + m.yb*v.y + m.yc*v.z + m.yd*v.w;
	result.z = m.za*v.x + m.zb*v.y + m.zc*v.z + m.zd*v.w;
	result.w = m.wa*v.x + m.wb*v.y + m.wc*v.z + m.wd*v.w;
	return result;
}

// inline Vec3 operator*(Mat4 m, Vec3 v) {
// 	Vec4 result = m*vec4(v,0);
// 	return result.xyz;
// }

inline void rowToColumn(Mat4* m) {
	for(int x = 1; x < 4; x++) {
		for(int y = 0; y < x; y++) {
			float temp = m->e2[y][x];
			m->e2[y][x] = m->e2[x][y];
			m->e2[x][y] = temp;
		}
	}
}

inline void identityMatrix(Mat4* m) {
	*m = { 1,0,0,0, 
	       0,1,0,0, 
	       0,0,1,0, 
	       0,0,0,1 };
}
inline Mat4 identityMatrix() {
	Mat4 m;
	identityMatrix(&m);
	return m;
}

inline void scaleMatrix(Mat4* m, Vec3 a) {
	*m = {};
	m->x1 = a.x;
	m->y2 = a.y;
	m->z3 = a.z;
	m->w4 = 1;
}

inline Mat4 scaleMatrix(Vec3 a) {
	Mat4 m = {};
	m.x1 = a.x;
	m.y2 = a.y;
	m.z3 = a.z;
	m.w4 = 1;

	return m;
}

inline void rotationMatrix(Mat4* m, Vec3 a) {
	*m = {  cosf(a.y)*cosf(a.z), cosf(a.z)*sinf(a.x)*sinf(a.y)-cosf(a.x)*sinf(a.z),  cosf(a.x)*cosf(a.z)*sinf(a.x)+sinf(a.x)*sinf(a.z), 0,
			  cosf(a.y)*sinf(a.z), cosf(a.x)*cosf(a.z)+sinf(a.x)*sinf(a.y)*sinf(a.z), -cosf(a.z)*sinf(a.x)+cosf(a.x)*sinf(a.y)*sinf(a.z), 0,
			           -sinf(a.y),                               cosf(a.y)*sinf(a.x), 							            cosf(a.x)*cosf(a.y), 0,
			                    0,                                                 0,                                                  0, 1};
}

inline void rotationMatrixX(Mat4* m, float a) {
	float ca = cos(a);
	float sa = sin(a);
	*m = { 1,   0,  0, 0,
			 0,  ca, sa, 0,
			 0, -sa, ca, 0,
			 0,   0,  0, 1};
}

inline void rotationMatrixY(Mat4* m, float a) {
	float ca = cos(a);
	float sa = sin(a);
	*m = { ca, 0, -sa, 0,
			  0, 1,   0, 0,
			 sa, 0,  ca, 0,
			  0, 0,   0, 1};
}

inline void rotationMatrixZ(Mat4* m, float a) {
	float ca = cos(a);
	float sa = sin(a);
	*m = { ca, sa, 0, 0,
			-sa, ca, 0, 0,
			  0,  0, 1, 0,
			  0,  0, 0, 1};
}

inline void translationMatrix(Mat4* m, Vec3 a) {
	*m = {};
	m->x1 = 1;
	m->y2 = 1;
	m->z3 = 1;
	m->w4 = 1;

	m->w1 = a.x;
	m->w2 = a.y;
	m->w3 = a.z;
}

inline Mat4 translationMatrix(Vec3 a) {
	Mat4 m = {};
	m.x1 = 1;
	m.y2 = 1;
	m.z3 = 1;
	m.w4 = 1;

	m.w1 = a.x;
	m.w2 = a.y;
	m.w3 = a.z;

	return m;
}

inline void viewMatrix(Mat4* m, Vec3 cPos, Vec3 cLook, Vec3 cUp, Vec3 cRight) {
	*m = { 
		cRight.x, cRight.y, cRight.z, -(dot(cPos,cRight)), 
	   cUp.x,    cUp.y,    cUp.z,    -(dot(cPos,cUp)), 
	   cLook.x,  cLook.y,  cLook.z,  -(dot(cPos,cLook)), 
	   0,        0,        0,        1 
	};
}

inline Mat4 viewMatrix(Vec3 cPos, Vec3 cLook, Vec3 cUp, Vec3 cRight) {
	Mat4 m;
	viewMatrix(&m, cPos, cLook, cUp, cRight);
	return m;
}

inline Mat4 viewMatrix(Vec3 pos, Vec3 look) {
	look = norm(look);
	Vec3 right = norm(cross(vec3(0,0,1), look));
	Vec3 up = norm(cross(look, right));

	return viewMatrix(pos, -look, up, right);
}

inline Mat4 viewMatrix(Vec3 pos, Vec3 look, Vec3 right) {
	look = norm(look);
	right = norm(right);
	Vec3 up = norm(cross(look, right));

	return viewMatrix(pos, -look, up, right);
}

inline void viewMatrixInv(Mat4* m, Vec3 cPos, Vec3 cLook, Vec3 cUp, Vec3 cRight) {
	*m = { 
		cRight.x, cUp.x, cLook.x, cPos.x*cRight.x + cPos.y*cUp.x + cPos.z*cLook.x, 
	   cRight.y, cUp.y, cLook.y, cPos.x*cRight.y + cPos.y*cUp.y + cPos.z*cLook.y, 
	   cRight.z, cUp.z, cLook.z, cPos.x*cRight.z + cPos.y*cUp.z + cPos.z*cLook.z, 
	   0,        0,     0,       1 
	};
}

inline Mat4 viewMatrixInv(Vec3 cPos, Vec3 cLook, Vec3 cUp, Vec3 cRight) {
	Mat4 m;
	viewMatrixInv(&m, cPos, cLook, cUp, cRight);
	return m;
}

inline void projMatrix(Mat4* m, float fov, float ar, float n, float f) {
	// ar -> w / h
	// fov -> vertical
	*m = { 
		1/(ar*tanf(fov*0.5f)), 0,                  0,              0,
		0,                     1/(tanf(fov*0.5f)), 0,              0,
		0,                     0,                 -((f+n)/(f-n)), -((2*f*n)/(f-n)),
		0,                     0,                 -1,              0 
	};
}

inline Mat4 projMatrix(float fov, float ar, float n, float f) {
	Mat4 m;
	projMatrix(&m, fov, ar, n, f);
	return m;
}

inline void orthoMatrix(Mat4* m, float l, float b, float r, float t, float n, float f) {
	*m = { 
		2/(r-l), 0,       0,        -(r+l)/(r-l),
		0,       2/(t-b), 0,        -(t+b)/(t-b),
		0,       0,       -2/(f-n), -(f+n)/(f-n),
		0,       0,       0,        1 
	};
}

inline Mat4 orthoMatrix(float l, float b, float r, float t, float n, float f) {
	Mat4 m;
	orthoMatrix(&m, l, b, r, t, n, f);
	return m;
}

//

inline void projMatrixZ01(Mat4* m, float fov, float ar, float n, float f) {
	float yScale = (1/tan(fov/2.0f));
	float xScale = yScale / ar;

	*m = { 
		xScale, 0,      0,       0,
		0,      yScale, 0,       0,
		0,      0,      f/(n-f), (f*n)/(n-f),
		0,      0,     -1,       0 
	};
}

inline Mat4 projMatrixZ01(float fov, float ar, float n, float f) {
	Mat4 m;
	projMatrixZ01(&m, fov, ar, n, f);

	return m;
}

inline Mat4 projMatrixZ01Inv(Mat4 m) {
	float a = m.xa;
	float b = m.yb;
	float c = m.zc;
	float d = m.zd;
	float e = m.wc;

	m.xa = 1/a;
	m.yb = 1/b;
	m.zc = 0;
	m.zd = 1/e;
	m.wc = 1/d;
	m.wd = -c/(d*e);

	return m;
}

inline void orthoMatrixZ01(Mat4* m, float l, float b, float r, float t, float n, float f) {
	*m = { 
		2/(r-l), 0,       0,       -(r+l)/(r-l),
		0,       2/(t-b), 0,       -(t+b)/(t-b),
		0,       0,       1/(f-n), n/(n-f),
		0,       0,       0,       1 
	};
}

inline Mat4 orthoMatrixZ01(float l, float b, float r, float t, float n, float f) {
	Mat4 m;
	orthoMatrixZ01(&m, l, b, r, t, n, f);
	return m;
}

inline Mat4 orthoMatrixZ01(float w, float h, float n, float f) {
	Mat4 m = { 
		1/(w/2), 0,       0,       0,
		0,       1/(h/2), 0,       0,
		0,       0,       1/(f-n), n/(n-f),
		0,       0,       0,       1 
	};

	return m;
}

//
// @Quat
//

Quat quat() { return {1,0,0,0}; }
Quat quat(float w, float x, float y, float z) { return {w,x,y,z}; }
Quat quat(float a, Vec3 axis) {
	Quat r;
	r.w = cos(a*0.5f);
	r.x = axis.x * sin(a*0.5f);
	r.y = axis.y * sin(a*0.5f);
	r.z = axis.z * sin(a*0.5f);
	return r;
}

Quat quatDeg(float degrees, Vec3 axis) {
	return quat(degreeToRadian(degrees), axis);
}

float quatGetAxisAngle(Quat q, Vec3* axis) {
	float angle = 2 * acos(q.w);
	axis->x = q.x / sqrt(1-q.w*q.w);
	axis->y = q.y / sqrt(1-q.w*q.w);
	axis->z = q.z / sqrt(1-q.w*q.w);
	return angle;
}

// Not the right name for this.
float dot(Quat q) {
	return (q.w*q.w + q.x*q.x + q.y*q.y + q.z*q.z);
}

float magnitude(Quat q) {
	return sqrt(dot(q));
}

Quat norm(Quat q) {
	Quat result;
	float m = magnitude(q);
	return quat(q.w/m, q.x/m, q.y/m, q.z/m);
}

Quat quatConjugate(Quat q) {
	return quat(q.w, -q.x, -q.y, -q.z);
}

Quat quatScale(Quat q, float s) {
	return quat(q.w*s, q.x*s, q.y*s, q.z*s);
}

Quat inverse(Quat q) {
	return quatScale(quatConjugate(q), (1.0f/dot(q)));
}

Quat operator*(Quat a, Quat b) {
	Quat r;
	r.w = (a.w*b.w - a.x*b.x - a.y*b.y - a.z*b.z);
	r.x = (a.w*b.x + a.x*b.w + a.y*b.z - a.z*b.y);
	r.y = (a.w*b.y - a.x*b.z + a.y*b.w + a.z*b.x);
	r.z = (a.w*b.z + a.x*b.y - a.y*b.x + a.z*b.w);
	return r;
}

// Does not make sense. Only used internally once.
Quat operator-(Quat a, Quat b) {
	Quat r;
	r.w = a.w - b.w;
	r.x = a.x - b.x;
	r.y = a.y - b.y;
	r.z = a.z - b.z;

	return r;
}
Quat operator+(Quat a, Quat b) {
	Quat r;
	r.w = a.w + b.w;
	r.x = a.x + b.x;
	r.y = a.y + b.y;
	r.z = a.z + b.z;

	return r;
}

Vec3 operator*(Quat q, Vec3 v) {
	Vec3 t = 2 * cross(q.xyz, v);
	Vec3 result = v + q.w * t + cross(q.xyz, t);

	return result;
}

bool operator==(Quat q0, Quat q1) {
	return q0.w==q1.w && q0.x==q1.x && q0.y==q1.y && q0.z==q1.z;
}

void rotationMatrix(Mat4* m, Quat q) {
	float w = q.w, x = q.x, y = q.y, z = q.z;
	float x2 = x*x, y2 = y*y, z2 = z*z;
	float w2 = w*w;
	*m = {	w2+x2-y2-z2, 2*x*y-2*w*z, 2*x*z+2*w*y, 0,
			2*x*y+2*w*z, w2-x2+y2-z2, 2*y*z-2*w*x, 0,
			2*x*z-2*w*y, 2*y*z+2*w*x, w2-x2-y2+z2, 0,
			0, 			 0, 		  0, 		   1};
}

Mat4 rotationMatrix(Quat q) {
	float w = q.w, x = q.x, y = q.y, z = q.z;
	float x2 = x*x, y2 = y*y, z2 = z*z;
	float w2 = w*w;
	Mat4 m = {	w2+x2-y2-z2, 2*x*y-2*w*z, 2*x*z+2*w*y, 0,
				2*x*y+2*w*z, w2-x2+y2-z2, 2*y*z-2*w*x, 0,
				2*x*z-2*w*y, 2*y*z+2*w*x, w2-x2-y2+z2, 0,
				0, 			 0, 		  0, 		   1};

	return m;
}

Mat4 modelMatrix(Vec3 trans, Vec3 scale, float degrees = 0, Vec3 rot = vec3(0,0,0)) {
	Mat4 tm = translationMatrix(trans);
	Mat4 rm = rotationMatrix(quat(degrees, rot));
	Mat4 sm = scaleMatrix(scale);
	Mat4 model = tm*rm*sm;

	return model;
}

Mat4 modelMatrix(Vec3 trans, Vec3 scale, Quat rot) {
	Mat4 tm = translationMatrix(trans);
	Mat4 rm = rotationMatrix(rot);
	Mat4 sm = scaleMatrix(scale);
	Mat4 model = tm*rm*sm;

	return model;
}

Mat4 modelMatrix(XForm xf) {
	return modelMatrix(xf.trans, xf.scale, xf.rot);
}

Mat4 modelMatrixInv(Vec3 trans, Vec3 scale, Quat rot) {
	Mat4 tm = translationMatrix(-trans);
	Mat4 rm = rotationMatrix(inverse(rot));
	Mat4 sm = scaleMatrix(1.0f/scale);
	Mat4 model = sm*rm*tm;

	return model;
}

Mat4 modelMatrixInv(XForm xf) {
	return modelMatrixInv(xf.trans, xf.scale, xf.rot);
}

Mat4 modelMatrixReverse(Vec3 trans, Vec3 scale, Quat rot) {
	Mat4 tm = translationMatrix(trans);
	Mat4 rm = rotationMatrix(rot);
	Mat4 sm = scaleMatrix(scale);
	Mat4 model = sm*rm*tm;

	return model;
}

Mat4 modelMatrixReverse(XForm xf) {
	return modelMatrixReverse(xf.trans, xf.scale, xf.rot);
}

Vec3 rotate(Vec3 v, float a, Vec3 axis) {
	Vec3 r = quat(a, axis)*v;
	return r;
}

void rotate(Vec3* v, float a, Vec3 axis) {
	*v = rotate(*v, a, axis);
}

Vec3 rotateAround(Vec3 v, float a, Vec3 axis, Vec3 point) {
	Vec3 aroundOrigin = rotate(v - point, a, axis);
	aroundOrigin += point;

	return aroundOrigin;
}

void rotateAround(Vec3* v, float a, Vec3 axis, Vec3 point) {
	*v = rotateAround(*v, a, axis, point);
}

Vec3 rotateAround(Vec3 v, Quat q, Vec3 point) {
	Vec3 aroundOrigin = point + (q * (v - point));

	return aroundOrigin;
}

void rotateAround(Vec3* v, Quat q, Vec3 point) {
	*v = rotateAround(*v, q, point);
}

Quat getQuatFromVecs(Vec3 start, Vec3 dest) {
	float angle;
	Vec3 axis = getRotationToVector(start, dest, &angle);
	return quat(angle, axis);
}	

// From Wikipedia.
Quat eulerAnglesToQuat(float pitch, float roll, float yaw) {
	Quat q;

    // Abbreviations for the various angular functions
	float cy = cos(yaw * 0.5);
	float sy = sin(yaw * 0.5);
	float cr = cos(roll * 0.5);
	float sr = sin(roll * 0.5);
	float cp = cos(pitch * 0.5);
	float sp = sin(pitch * 0.5);

	q.w = cy * cr * cp + sy * sr * sp;
	q.x = cy * sr * cp - sy * cr * sp;
	q.y = cy * cr * sp + sy * sr * cp;
	q.z = sy * cr * cp - cy * sr * sp;
	return q;
}
void quatToEulerAngles(Quat q, float* pitch, float* roll, float* yaw) {
	// roll (x-axis rotation)
	float sinr = +2.0 * (q.w * q.x + q.y * q.z);
	float cosr = +1.0 - 2.0 * (q.x * q.x + q.y * q.y);
	if(roll) *roll = atan2(sinr, cosr);

	// pitch (y-axis rotation)
	float sinp = +2.0 * (q.w * q.y - q.z * q.x);
	if (fabs(sinp) >= 1) {
		if(pitch) *pitch = copysign((float)M_PI / 2.0f, sinp); // use 90 degrees if out of range
	} else {
		if(pitch) *pitch = asin(sinp);
	}

	if(yaw) {
		// yaw (z-axis rotation)
		float siny = +2.0 * (q.w * q.z + q.x * q.y);
		float cosy = +1.0 - 2.0 * (q.y * q.y + q.z * q.z);  
		*yaw = atan2(siny, cosy);
	}
}

Quat orientationToQuat(Vec3 orientation) {
	Quat q = quat(orientation.z, vec3(0,0,1)) *
	         quat(orientation.y, vec3(0,1,0)) *
	         quat(orientation.x, vec3(1,0,0));

	return q;
}

Quat lerp(Quat q1, Quat q2, float t) {
	Quat q;

	float tm = 1 - t;
	q.x = tm*q1.x + t*q2.x;
	q.y = tm*q1.y + t*q2.y;
	q.z = tm*q1.z + t*q2.z;
	q.w = tm*q1.w + t*q2.w;

	q = norm(q);
	return q;
}

//
// @XForms
//

XForm xForm(Vec3 trans, Quat rot, Vec3 scale) { return { trans, rot, scale }; }
XForm xForm(Vec3 trans, Quat rot) { return { trans, rot, vec3(1.0f) }; }
XForm xForm(Vec3 trans, Vec3 scale) { return { trans, quat(), scale }; }
XForm xForm(Vec3 trans) { return { trans, quat(), vec3(1.0f) }; }
XForm xForm() { return { vec3(0.0f), quat(), vec3(1.0f) }; }
XForm xForm(Rect3 r) { return { r.c(), quat(), r.dim() }; }

// Slow...
inline Vec3 operator*(XForm xf, Vec3 v) {
	return xf.trans + xf.rot * (xf.scale * v);
}

inline Vec3 mulInverse(XForm xf, Vec3 v) {
	return (inverse(xf.rot) * (v - xf.trans)) / xf.scale;
}

inline Vec3 mulInverseNoTrans(XForm xf, Vec3 v) {
	return (inverse(xf.rot) * v) / xf.scale;
}

inline Vec3 mulReverse(XForm xf, Vec3 v) {
	return  xf.scale * (xf.rot * (v + xf.trans));
}

inline Vec3 mulReverseNoTrans(XForm xf, Vec3 v) {
	return xf.scale * (xf.rot * v);
}

inline XForm operator*(XForm a, XForm b) {
	XForm xf;

	xf.trans = a.trans + a.rot * (a.scale * b.trans);
	xf.rot = a.rot * b.rot;
	xf.scale = inverse(b.rot) * (a.scale * (b.rot * b.scale));

	return xf;
}

inline XForm inverse(XForm a) {
	Quat aRotInv = inverse(a.rot);

	XForm inv;
	inv.trans = (aRotInv*(-a.trans)) / a.scale;
	inv.rot   = aRotInv;
	inv.scale = a.rot * ((aRotInv*vec3(1)) / a.scale);
	
	return inv;
}

inline XForm inverseSplit(XForm a) {
	a.trans = -a.trans;
	a.rot = inverse(a.rot);
	a.scale = 1.0f/a.scale;
	return a;
}

inline Rect3 boundingBox(Mat4 mat) {
	Rect3 bb = {vec3(FLT_MAX), vec3(-FLT_MAX)};

	for(int x = 0; x < 2; x++) {
		for(int y = 0; y < 2; y++) {
			for(int z = 0; z < 2; z++) {
				Vec3 p = vec3(x?-0.5f:0.5f,y?-0.5f:0.5f,z?-0.5f:0.5f);
				Vec3 rp = (mat * vec4(p,1)).xyz;

				bb.min = min(bb.min, rp);
				bb.max = max(bb.max, rp);
			}
		}
	}

	return bb;
}

inline Rect3 boundingBox(XForm xf) {
	return boundingBox(modelMatrix(xf));
}

// https://github.com/erich666/GraphicsGems/blob/master/gems/TransBox.c
/*
Transforming Axis-Aligned Bounding Boxes
by Jim Arvo
from "Graphics Gems", Academic Press, 1990
*/
Rect3 transformBoundingBox(Rect3 bb, Mat4 m) {
	/* Take care of translation by beginning at T. */
	Rect3 rb;
	rb.min = rb.max = vec3(m.w1, m.w2, m.w3);

	/* Now find the extreme points by considering the product of the */
	/* min and max with each component of M.  */
	for(int i = 0; i < 3; i++)
	for(int j = 0; j < 3; j++) {
		float a = m.e2[i][j] * bb.min.e[j];
		float b = m.e2[i][j] * bb.max.e[j];
		if(a < b) {
			rb.min.e[i] += a; 
			rb.max.e[i] += b;
		} else { 
			rb.min.e[i] += b; 
			rb.max.e[i] += a;
		}
	}

	return rb;
} 

// Name not correct.
inline XForm aabbToObb(XForm xf, Quat rot) {
	xf.rot = xf.rot * inverse(rot);
	Rect3 rbb = boundingBox(xf);
	XForm xf2 = xForm(rbb.c(), rbb.dim());
	xf2.rot = xf2.rot * rot;

	return xf2;
}

inline void transformInverse(Vec3 pos, Vec3 dir, XForm xfInv, Vec3& posTransformed, Vec3& dirTransformed) {
	bool isRotated = !(xfInv.rot == quat());

	pos = pos + xfInv.trans;
	if(isRotated) pos = xfInv.rot * pos;
	pos = pos * xfInv.scale;
	posTransformed = pos;

	if(isRotated) dir = xfInv.rot * dir;
	dir = dir * xfInv.scale;
	dirTransformed = dir;
}

//
// @Rect
//

inline Rect  rect       () { return {0,0,0,0}; }
inline Rect  rect       (Vec2 min, Vec2 max) { return {min, max}; }
inline Rect  rect       (float l, float b, float r, float t) { return {l, b, r, t}; }
inline Rect  rectSides  (float l, float b, float r, float t) { return {l, b, r, t}; }
inline Rect  rectCenDim (Vec2 a, Vec2 d)    { return {a.x-d.w/2, a.y - d.h/2, a.x + d.w/2, a.y + d.h/2}; };
inline Rect  rectBLDim  (Vec2 a, Vec2 d)    { return {a, a+d}; };
inline Rect  rectTLDim  (Vec2 a, Vec2 d)    { return {a.x, a.y-d.h, a.x+d.w, a.y}; };
inline Rect  rectTRDim  (Vec2 a, Vec2 d)    { return {a-d, a}; };
inline Rect  rectBRDim  (Vec2 a, Vec2 d)    { return {a.x-d.w, a.y, a.x, a.y+d.h}; };
inline Rect  rectLDim   (Vec2 a, Vec2 d)    { return {a.x, a.y-d.h/2, a.x+d.w, a.y+d.h/2}; };
inline Rect  rectTDim   (Vec2 a, Vec2 d)    { return {a.x-d.w/2, a.y-d.h, a.x+d.w/2, a.y}; };
inline Rect  rectRDim   (Vec2 a, Vec2 d)    { return {a.x-d.w, a.y-d.h/2, a.x, a.y+d.h/2}; };
inline Rect  rectBDim   (Vec2 a, Vec2 d)    { return {a.x-d.w/2, a.y, a.x+d.w/2, a.y+d.h}; };
inline Rect  rectCenDim (float x, float y, float w, float h) { return rectCenDim({x,y}, {w,h});};
inline Rect  rectBLDim  (float x, float y, float w, float h) { return rectBLDim({x,y}, {w,h}); };
inline Rect  rectTLDim  (float x, float y, float w, float h) { return rectTLDim({x,y}, {w,h}); };
inline Rect  rectTRDim  (float x, float y, float w, float h) { return rectTRDim({x,y}, {w,h}); };
inline Rect  rectBRDim  (float x, float y, float w, float h) { return rectBRDim({x,y}, {w,h}); };
inline Rect  rectLDim   (float x, float y, float w, float h) { return rectLDim({x,y}, {w,h}); };
inline Rect  rectTDim   (float x, float y, float w, float h) { return rectTDim({x,y}, {w,h}); };
inline Rect  rectRDim   (float x, float y, float w, float h) { return rectRDim({x,y}, {w,h}); };
inline Rect  rectBDim   (float x, float y, float w, float h) { return rectBDim({x,y}, {w,h}); };

inline float Rect::w    () { return right - left; };
inline float Rect::h    () { return top - bottom; };
inline float Rect::cx   () { return left + w()/2; };
inline float Rect::cy   () { return bottom + h()/2; };
inline Vec2  Rect::dim  () { return max - min; };
inline Vec2  Rect::c    () { return min + dim()/2; };
inline Vec2  Rect::bl   () { return min; }
inline Vec2  Rect::l    () { return {left, c().y}; }
inline Vec2  Rect::tl   () { return {left, top}; }
inline Vec2  Rect::t    () { return {c().x, top}; }
inline Vec2  Rect::tr   () { return max; }
inline Vec2  Rect::r    () { return {right, c().y}; }
inline Vec2  Rect::br   () { return {right, bottom}; }
inline Vec2  Rect::b    () { return {c().x, bottom}; }

inline Rect operator+(Rect r, Vec2 off) { return {r.min+off, r.max+off}; };
inline Rect & operator+=(Rect& r, Vec2 off) { return r = r + off; };
inline Rect operator*(Rect r, Vec2 dim) { return rectCenDim(r.c(), r.dim()*dim); };
inline Rect operator*(Rect r, float s) { return rectCenDim(r.c(), r.dim()*s); };
inline Rect operator*=(Rect r, Vec2 dim) { return r = r * dim; };
inline Rect operator*=(Rect r, float s) { return r = r * s; };

inline Rect Rect::setC   (Vec2 p)    { return rectCenDim(p, dim()); }
inline Rect Rect::setDim (Vec2 d)    { return rectCenDim(c(), d); }
inline Rect Rect::setW   (float p)   { return rectCenDim(c(), vec2(p, h())); }
inline Rect Rect::setH   (float p)   { return rectCenDim(c(), vec2(w(), p)); }
inline Rect Rect::setBL  (Vec2 p)    { return {p.x, p.y, right, top}; }
inline Rect Rect::setTL  (Vec2 p)    { return {p.x, bottom, right, p.y}; }
inline Rect Rect::setTR  (Vec2 p)    { return {left, bottom, p.x, p.y}; }
inline Rect Rect::setBR  (Vec2 p)    { return {left, p.y, p.x, top}; }
inline Rect Rect::setL   (float p)   { return {p, bottom, right, top}; }
inline Rect Rect::setT   (float p)   { return {left, bottom, right, p}; }
inline Rect Rect::setR   (float p)   { return {left, bottom, p, top}; }
inline Rect Rect::setB   (float p)   { return {left, p, right, top}; }
inline Rect Rect::rSetL  (float p)   { return {right - p, bottom, right, top}; }
inline Rect Rect::rSetT  (float p)   { return {left, bottom, right, bottom + p}; }
inline Rect Rect::rSetR  (float p)   { return {left, bottom, left + p, top}; }
inline Rect Rect::rSetB  (float p)   { return {left, top - p, right, top}; }
inline Rect Rect::expand (Vec2 dim)  { return {min-dim/2, max+dim/2}; }
inline Rect Rect::expand (float s)   { return {min-vec2(s)/2, max+vec2(s)/2}; }
inline Rect Rect::trans  (Vec2 off)  { return {min+off, max+off}; }
inline Rect Rect::addBL  (Vec2 p)    { return {left + p.x, bottom + p.y, right, top}; }
inline Rect Rect::addTL  (Vec2 p)    { return {left + p.x, bottom, right, top + p.y}; }
inline Rect Rect::addTR  (Vec2 p)    { return {left, bottom, right + p.x, top + p.y}; }
inline Rect Rect::addBR  (Vec2 p)    { return {left, bottom + p.y, right + p.x, top}; }
inline Rect Rect::addL   (float p)   { return {left + p, bottom, right, top}; }
inline Rect Rect::addT   (float p)   { return {left, bottom, right, top + p}; }
inline Rect Rect::addR   (float p)   { return {left, bottom, right + p, top}; }
inline Rect Rect::addB   (float p)   { return {left, bottom + p, right, top}; }

inline Rect Rect::expand (float l, float b, float r, float t) { 
	return {left+l, bottom+b, right+r, top+t}; 
}

inline Rect Rect::cenDim() { return {min + (max-min)/2, max-min}; };
inline Rect Rect::minMax() { return {center - dimension/2, center + dimension/2}; };

inline bool Rect::empty() { return left==0.0f && right==0.0f && top==0.0f && bottom==0.0f; };
inline bool Rect::zero()  { return w() <= 0.0f || h() <= 0.0f; };

//

Vec2 rectAlign(Rect r, Vec2i align) {
	     if(align == vec2i( 0, 0)) return r.c();
	else if(align == vec2i(-1,-1)) return r.bl();
	else if(align == vec2i(-1, 0)) return r.l();
	else if(align == vec2i(-1, 1)) return r.tl();
	else if(align == vec2i( 0, 1)) return r.t();
	else if(align == vec2i( 1, 1)) return r.tr();
	else if(align == vec2i( 1, 0)) return r.r();
	else if(align == vec2i( 1,-1)) return r.br();
	else if(align == vec2i( 0,-1)) return r.b();

	return vec2(0,0);
}

Rect rectAlignDim(Vec2 v, Vec2i align, Vec2 dim) {
	     if(align == vec2i(0,  0)) return rectCenDim( v, dim );
	else if(align == vec2i(-1,-1)) return rectBLDim ( v, dim );
	else if(align == vec2i(-1, 0)) return rectLDim  ( v, dim );
	else if(align == vec2i(-1, 1)) return rectTLDim ( v, dim );
	else if(align == vec2i( 0, 1)) return rectTDim  ( v, dim );
	else if(align == vec2i( 1, 1)) return rectTRDim ( v, dim );
	else if(align == vec2i( 1, 0)) return rectRDim  ( v, dim );
	else if(align == vec2i( 1,-1)) return rectBRDim ( v, dim );
	else if(align == vec2i( 0,-1)) return rectBDim  ( v, dim );

	return rect(0,0,0,0);
}

Rect rectAlignDim(Rect r, Vec2i align, Vec2 dim) {
	     if(align == vec2i(0,  0)) return rectCenDim( r.c(), dim );
	else if(align == vec2i(-1,-1)) return rectBLDim ( r.bl(), dim );
	else if(align == vec2i(-1, 0)) return rectLDim  ( r.l(), dim );
	else if(align == vec2i(-1, 1)) return rectTLDim ( r.tl(), dim );
	else if(align == vec2i( 0, 1)) return rectTDim  ( r.t(), dim );
	else if(align == vec2i( 1, 1)) return rectTRDim ( r.tr(), dim );
	else if(align == vec2i( 1, 0)) return rectRDim  ( r.r(), dim );
	else if(align == vec2i( 1,-1)) return rectBRDim ( r.br(), dim );
	else if(align == vec2i( 0,-1)) return rectBDim  ( r.b(), dim );

	return r;
}

inline bool operator==(Rect r1, Rect r2) { return (r1.min == r2.min) && (r1.max == r2.max); }
inline bool operator!=(Rect r1, Rect r2) { return (r1.min != r2.min) && (r1.max != r2.max); }

inline bool rectIntersection(Rect r1, Rect r2) {
	bool hasIntersection = !(r2.min.x > r1.max.x ||
							 r2.max.x < r1.min.x ||
							 r2.max.y < r1.min.y ||
							 r2.min.y > r1.max.y);
	return hasIntersection;
}

Rect rectIntersect(Rect r1, Rect r2) {
	bool hasIntersection = rectIntersection(r1, r2);
	Rect intersectionRect;
	if (hasIntersection) {
		intersectionRect.min.x = max(r1.min.x, r2.min.x);
		intersectionRect.max.x = min(r1.max.x, r2.max.x);
		intersectionRect.max.y = min(r1.max.y, r2.max.y);
		intersectionRect.min.y = max(r1.min.y, r2.min.y);
	} else intersectionRect = rect(0,0,0,0);
	
	return intersectionRect;
};

bool rectGetIntersection(Rect * intersectionRect, Rect r1, Rect r2) {
	bool hasIntersection = rectIntersection(r1, r2);
	if (hasIntersection) {
		intersectionRect->min.x = max(r1.min.x, r2.min.x);
		intersectionRect->max.x = min(r1.max.x, r2.max.x);
		intersectionRect->max.y = min(r1.max.y, r2.max.y);
		intersectionRect->min.y = max(r1.min.y, r2.min.y);
	}
	else *intersectionRect = rect(0,0,0,0);
	
	return hasIntersection;
};

bool pointInRect(Vec2 p, Rect r) {
	bool inRect = ( p.x >= r.min.x &&
					p.x <= r.max.x &&
					p.y >= r.min.y &&
					p.y <= r.max.y   );

	return inRect;
}

bool pointInRectEx(Vec2 p, Rect r) {
	bool inRect = ( p.x >= r.min.x &&
					p.x <  r.max.x &&
					p.y >= r.min.y &&
					p.y <  r.max.y   );

	return inRect;
}

bool rectInsideRect(Rect r0, Rect r1) {
	bool result = (r0.min.x > r1.min.x &&
	               r0.min.y > r1.min.y &&
	               r0.max.x < r1.max.x &&
	               r0.max.y < r1.max.y);
	return result;
}

Vec2 rectInsideRectClamp(Rect r0, Rect r1) {
	Vec2 offset = vec2(0,0);
	if(r0.min.x < r1.min.x) offset += vec2(r1.min.x-r0.min.x, 0);
	if(r0.min.y < r1.min.y) offset += vec2(0, r1.min.y-r0.min.y);
	if(r0.max.x > r1.max.x) offset += vec2(r1.max.x-r0.max.x, 0);
	if(r0.max.y > r1.max.y) offset += vec2(0, r1.max.y-r0.max.y);

	return offset;
}

Vec2 rectDistancePos(Rect r, Vec2 p) {
	Vec2 result;
		 if(p.x >= r.max.x) result.x = p.x - r.max.x;
	else if(p.x <= r.min.x) result.x = p.x - r.min.x;
		 if(p.y >= r.max.y) result.y = p.y - r.max.y;
	else if(p.y <= r.min.y) result.y = p.y - r.min.y;
	return result;
}

Rect mapRange(Rect r, Rect oldInterp, Rect newInterp) {
	Rect result = r;
	result.min = mapRange(result.min, oldInterp.min, oldInterp.max, newInterp.min, newInterp.max);
	result.max = mapRange(result.max, oldInterp.min, oldInterp.max, newInterp.min, newInterp.max);

	return result;
}

Rect round(Rect r) {
	for(int i = 0; i < 4; i++) r.e[i] = roundf(r.e[i]);
	return r;
}

//
// @Recti
//

inline Recti recti() { return {0,0,0,0}; }
inline Recti recti(int l, int b, int r, int t) { return {l,b,r,t}; }
inline Recti rectiRound(Rect r) {
	return recti(roundIntf(r.left), roundIntf(r.bottom), 
	             roundIntf(r.right), roundIntf(r.top));
}
inline Recti recti       (Vec2i min, Vec2i max) { return {min, max}; }
inline Recti rectiCenDim (Vec2i a, Vec2i d)     { return {a.x-d.w/2, a.y - d.h/2, a.x + d.w/2, a.y + d.h/2}; };

inline float Recti::w   () { return right - left; };
inline float Recti::h   () { return top - bottom; };
inline float Recti::cx  () { return left + w()/2; };
inline float Recti::cy  () { return bottom + h()/2; };
inline Vec2i Recti::dim () { return max - min; };
inline Vec2i Recti::c   () { return min + dim()/2; };

inline bool rectIntersection(Recti r1, Recti r2) {
	bool hasIntersection = !(r2.min.x > r1.max.x ||
							       r2.max.x < r1.min.x ||
							       r2.max.y < r1.min.y ||
							       r2.min.y > r1.max.y);
	return hasIntersection;
}

bool rectGetIntersection(Recti* intersectionRect, Recti r1, Recti r2) {
	bool hasIntersection = rectIntersection(r1, r2);
	if (hasIntersection) {
		intersectionRect->min.x = max(r1.min.x, r2.min.x);
		intersectionRect->max.x = min(r1.max.x, r2.max.x);
		intersectionRect->max.y = min(r1.max.y, r2.max.y);
		intersectionRect->min.y = max(r1.min.y, r2.min.y);
	}
	else *intersectionRect = recti(0,0,0,0);
	
	return hasIntersection;
};

//
// @Rect3
//

inline Rect3 rect3(Vec3 min, Vec3 max) { return {min, max}; };
inline Rect3 rect3CenDim(Vec3 cen, Vec3 dim) { return {cen-dim/2, cen+dim/2}; };

Rect3 rect3Expand(Rect3 r, Vec3 dim) { return {r.min-dim/2, r.max+dim/2}; };

inline Vec3  Rect3::dim  () { return max - min; };
inline Vec3  Rect3::c    () { return min + dim()/2; };

inline bool operator==(Rect3 a, Rect3 b) { return a.min == b.min && a.max == b.max; };

//
// @Rect3i
//

inline Rect3i rect3i(Vec3i min, Vec3i max) { return {min, max}; };
inline Rect3i rect3iCenDim(Vec3i cen, Vec3i dim) { return {cen-dim/2, cen+dim/2}; };

Rect3i rect3iExpand(Rect3i r, Vec3i dim) { return {r.min-dim/2, r.max+dim/2}; };

//

float boxRaycastRotated(Vec3 lp, Vec3 ld, XForm xForm, Vec3* intersection = 0, Vec3* intersectionNormal = 0, bool secondIntersection = false) {

	bool rotated = xForm.rot == quat() ? false : true;

	Vec3 rotatedPos, rotatedDir;
	if(rotated) {
		rotatedPos = rotateAround(lp, inverse(xForm.rot), xForm.trans);
		rotatedDir = rotateAround(lp + ld, inverse(xForm.rot), xForm.trans);
		rotatedDir = norm(rotatedDir - rotatedPos);
	} else {
		rotatedPos = lp;
		rotatedDir = ld;
	}

	float distance = lineBoxIntersection(rotatedPos, rotatedDir, xForm.trans, xForm.scale, intersection, intersectionNormal, secondIntersection);
	if(distance != -1) {
		if(intersectionNormal) {
			if(rotated) *intersectionNormal = xForm.rot * (*intersectionNormal);
		}
	}

	return distance;
}