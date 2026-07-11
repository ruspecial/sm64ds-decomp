typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long long s64;

typedef struct { s32 x, y; } Vec2;

struct Sub
{
    u8 pad0[0x30];
    /* 0x30 */ u8 b30;
    u8 pad31[0x3a - 0x31];
    /* 0x3a */ u8 b3a;
};

struct Stage
{
    u8 pad0[8];
    /* 0x08 */ u8 flags8;
    u8 pad9[0x4668 - 9];
    /* 0x4668 */ s32 n668;
    /* 0x466c */ s32 n66c;
    /* 0x4670 */ s32 n670;
    u8 pad4674[0x4684 - 0x4674];
    /* 0x4684 */ struct Sub *arr684[1];
    /* 0x4688 */ struct Sub *arr688[13];
    /* 0x46bc */ struct Sub *arr6bc[1];
    u8 padB[0x4720 - (0x46bc + 4)];
    /* 0x4720 */ struct Sub *arr720[1];
};

typedef struct Obj
{
    u8 pad0[4];
    /* 0x04 */ struct Stage *stage;
    /* 0x08 */ s32 posx;
    /* 0x0c */ s32 posy;
    u8 pad10[0x20 - 0x10];
    /* 0x20 */ s32 velx;
    /* 0x24 */ s32 vely;
    /* 0x28 */ s32 f28;
    /* 0x2c */ s32 idx;
    u8 pad30[0x3a - 0x30];
    /* 0x3a */ u8 f3a;
    u8 pad3b[0x44 - 0x3b];
    /* 0x44 */ s32 f44;
    /* 0x48 */ s32 f48;
    /* 0x4c */ u8 a4c[0x20];
    /* 0x6c */ u8 a6c[0x20];
    /* 0x8c */ u8 a8c[0x20];
    /* 0xac */ u8 aac[0x20];
    /* 0xcc */ u8 cc;
    /* 0xcd */ u8 cd;
    /* 0xce */ u8 ace[0x19];
    u8 pade7[0xf8 - 0xe7];
    /* 0xf8 */ s32 f8;
    u8 padfc[0x124 - 0xfc];
    /* 0x124 */ s32 f124;
    /* 0x128 */ u8 f128;
} Obj;

extern void func_211470c(Vec2 *out, struct Sub *s);
extern void func_21146f4(Vec2 *out, struct Sub *s);
extern void func_203d388(Vec2 *v, s32 a);
extern void func_203d434(Vec2 *v);
extern void func_203d480(Vec2 *out, Vec2 *v);
extern s32 func_203d570(Vec2 *v, Vec2 *w);
extern s64 func_203d5bc(Vec2 *v);
extern s32 func_203d614(Vec2 *v);
extern void func_203d630(Vec2 *v);
extern void func_203d6d0(Vec2 *out, Vec2 *a, Vec2 *b);
extern s32 func_203b990(void *p);
extern s32 func_21126b4(Obj *o, Vec2 *seg);
extern s32 func_2112504(Obj *o, Vec2 *seg);
extern s32 func_21122e0(Obj *o, Vec2 *seg);
extern s32 func_2112190(Obj *o, Vec2 *seg);
extern s32 func_2112030(Obj *o, Vec2 *seg);
extern s32 func_2111f8c(Obj *o, Vec2 *seg);
extern s32 func_2111ee8(Obj *o, Vec2 *seg);
extern s32 func_2111e90(Obj *o, Vec2 *seg);
extern s32 func_211248c(Obj *o, Vec2 *seg);
extern s32 func_21120d4(Obj *o, Vec2 *seg);
extern void func_2111b90(Obj *o, Vec2 *seg, void *tab);
extern void func_2111dcc(Obj *o, s32 a);
extern s32 func_21115c4(struct Sub *s);
extern void func_21115cc(struct Sub *s);
extern void func_2012718(void *h, s32 v);
extern s32 func_20126e8(s32 v);
extern void func_20126ac(void *h, s32 a, s32 b, s32 c);
extern void *gRandState;
extern void *gSndA, *gSndB, *gSndC, *gSndD;
extern void *gTabA, *gTabB, *gTabC, *gTabD;
extern s32 gMulK;

s32 func_ov006_02112ad8(Obj *o)
{
    s32 fA = 0, fB = 0, fC = 0, fD = 0, fE = 0, fF = 0;
    s32 savevx = o->velx;
    s32 savevy = o->vely;
    s32 mode = 0;
    s32 loops = 0;
    s32 acc = 0;
    s32 i;
    struct Stage *st;

    o->f8 = -1;
    for (i = 0; i < 0x20; i++)
    {
        o->a6c[i] = (u8)mode;
        o->aac[i] = (u8)mode;
        o->a8c[i] = (u8)mode;
    }
    o->cc = (u8)mode;
    o->cd = (u8)mode;

    if (o->posy < 0x77000)
    {
        s32 sb;
        Vec2 seg, tmp;
        for (sb = mode; sb < 0x19; sb++)
        {
            o->ace[sb] = 0;
            st = o->stage;
            if (sb < st->n670)
            {
                seg.x = o->posx;
                seg.y = o->posy;
                func_211470c(&tmp, (sb < st->n670) ? st->arr6bc[sb] : 0);
                seg.x = seg.x - tmp.x;
                seg.y = seg.y - tmp.y;
                if ((s64)0x900000 >= func_203d5bc(&seg))
                {
                    o->ace[sb] = 1;
                    mode = 1;
                }
            }
        }
    }
    else
    {
        for (i = mode; i < 0x19; i++)
            o->ace[i] = 0;
    }

    do
    {
        s32 outer, angle;
        s32 cx = 0, cy = 0;
        for (outer = 0, angle = 0; outer < 0x20; outer++, angle = (s16)(angle + 0x800))
        {
            Vec2 seg, t;
            s32 r;
            o->a4c[outer] = 0;
            seg.x = 0;
            seg.y = 0 + o->f28;
            func_203d388(&seg, angle);
            r = func_203d570(&seg, (Vec2 *)&o->velx);
            seg.x = seg.x + o->posx;
            seg.y = seg.y + o->posy;
            if (r >= 0)
            {
                st = o->stage;
                if ((st->flags8 & 0xff) == 0)
                {
                    t = seg;
                    if (func_21126b4(o, &t))
                    {
                        o->a4c[outer] = 1; o->a6c[outer] = 1; o->cc = 1; mode = 1;
                        goto endseg;
                    }
                    t = seg;
                    if (func_2112504(o, &t))
                    {
                        o->a4c[outer] = 1; o->a6c[outer] = 1; o->cc = 1; fA = 1; mode = 1;
                        goto endseg;
                    }
                    t = seg;
                    if (func_21122e0(o, &t))
                    {
                        o->a4c[outer] = 1; o->a6c[outer] = 1; o->cc = 1; o->a8c[outer] = 1; fC = 1; mode = 1;
                        goto endseg;
                    }
                }
                else
                {
                    t = seg;
                    if (func_21126b4(o, &t))
                    {
                        o->a4c[outer] = 1; o->a6c[outer] = 1; o->cc = 1; mode = 1;
                        goto endseg;
                    }
                    t = seg;
                    if (func_21122e0(o, &t))
                    {
                        o->a4c[outer] = 1; o->a6c[outer] = 1; o->cc = 1; o->a8c[outer] = 1; fB = 1; mode = 1;
                        goto endseg;
                    }
                    if (mode == 1)
                    {
                        t = seg;
                        if (func_2112190(o, &t))
                        {
                            o->a4c[outer] = 1; o->a6c[outer] = 1; o->cc = 1; o->cd = 1; fD = 1; mode = 1;
                            goto endseg;
                        }
                    }
                    t = seg;
                    if (func_2112030(o, &t))
                    {
                        o->a4c[outer] = 1; o->a6c[outer] = 1; o->cc = 1; mode = 1;
                        goto endseg;
                    }
                    t = seg;
                    if (func_2111f8c(o, &t))
                    {
                        o->a4c[outer] = 1; o->a6c[outer] = 1; o->cc = 1; mode = 1;
                        goto endseg;
                    }
                    t = seg;
                    if (func_2111ee8(o, &t))
                    {
                        o->a4c[outer] = 1; o->a6c[outer] = 1; o->cc = 1; mode = 1;
                        goto endseg;
                    }
                    t = seg;
                    if (func_2111e90(o, &t))
                    {
                        o->a4c[outer] = 1; o->a6c[outer] = 1; o->cc = 1; mode = 1; fE = 1;
                        goto endseg;
                    }
                }
            }
            if (mode == 0)
            {
                t = seg;
                if (func_211248c(o, &t))
                {
                    o->a4c[outer] = 1; o->a6c[outer] = 1; o->cc = 1; mode = 1;
                    if (angle == 0)
                        fF = 1;
                }
                else
                {
                    t = seg;
                    if (func_21120d4(o, &t))
                    {
                        o->a4c[outer] = 1; o->a6c[outer] = 1; o->cc = 1; mode = 1; fB = 1;
                    }
                }
            }
        endseg:
            ;
        }

        if (loops < 0x11 && o->f3a == 0)
        {
            s32 k8;
            st = o->stage;
            if (st->n668 > 0)
            {
                k8 = 0;
                do
                {
                    if (k8 != o->idx)
                    {
                        struct Sub *sub;
                        sub = (k8 < 0xd) ? st->arr688[k8] : 0;
                        if (sub->b3a == 0)
                        {
                            sub = (k8 < 0xd) ? st->arr688[k8] : 0;
                            if (sub->b30 != 0)
                            {
                                Vec2 base, dif, dif2;
                                sub = (k8 < 0xd) ? st->arr688[k8] : 0;
                                func_211470c(&base, sub);
                                func_203d6d0(&dif, (Vec2 *)&o->posx, &base);
                                dif2 = dif;
                                if ((s64)0x100000 >= func_203d5bc(&dif2))
                                {
                                    s32 k7, angle2;
                                    Vec2 sb2;
                                    sub = (k8 < 0xd) ? st->arr688[k8] : 0;
                                    func_211470c(&sb2, sub);
                                    if (!(o->posy >= 0x90000 && o->posx > sb2.x))
                                    {
                                        angle2 = 0;
                                        for (k7 = 0; k7 < 0x20; k7++, angle2 = (s16)(angle2 + 0x800))
                                        {
                                            Vec2 seg2, d3;
                                            seg2.x = 0;
                                            seg2.y = o->f28;
                                            func_203d388(&seg2, angle2);
                                            seg2.x = seg2.x + o->posx;
                                            seg2.y = seg2.y + o->posy;
                                            func_203d6d0(&d3, &seg2, &sb2);
                                            if ((s64)0x40000 > func_203d5bc(&d3))
                                            {
                                                o->f8 = k8;
                                                o->a4c[k7] = 1; o->a6c[k7] = 1; o->aac[k7] = 1;
                                                mode = 1;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    k8++;
                } while (k8 < st->n668);
            }
        }

        {
            s32 k, ang3;
            Vec2 sum;
            sum.x = 0;
            sum.y = 0;
            for (k = 0, ang3 = 0; k < 0x20; k++, ang3 = (s16)(ang3 + 0x800))
            {
                if (o->a4c[k] == 1)
                {
                    Vec2 v;
                    v.x = 0;
                    v.y = 0x1000;
                    func_203d388(&v, ang3);
                    sum.x = sum.x - v.x;
                    sum.y = sum.y - v.y;
                }
            }
            if (sum.x != 0 || sum.y != 0)
            {
                Vec2 nrm;
                s64 mx, my;
                s32 vx, vy;
                func_203d480(&nrm, &sum);
                mx = ((s64)o->velx * sum.x + 0x800) >> 12;
                my = ((s64)o->vely * sum.y + 0x800) >> 12;
                vx = (s32)(mx + my);
                if (mode != 1)
                {
                    s32 g = fF ? 0x1800 : 0;
                    if (fF)
                    {
                        vy = (s32)(((s64)vx * 0x1800 + 0x800) >> 12);
                    }
                    else if (fA)
                    {
                        s32 rnd;
                        vy = (s32)(((s64)vx * 0x1400 + 0x800) >> 12);
                        rnd = func_203b990(gRandState);
                        rnd = ((0x7fff & (rnd >> 16)) << 4) >> 15 << 12 >> 6;
                        vy = vy + rnd;
                        rnd = func_203b990(gRandState);
                        rnd = ((((0x7fff & (rnd >> 16)) << 12) >> 15) - 0x800);
                        func_203d388(&sum, (s16)rnd);
                    }
                    else if (fB)
                    {
                        s32 rnd;
                        o->velx = 0;
                        o->vely = 0;
                        rnd = func_203b990(gRandState);
                        rnd = ((0x7fff & (rnd >> 16)) << 4) >> 15 << 12 >> 5;
                        vy = -0x2000 + (s32)(((s64)rnd * -0x2000 + 0x800) >> 12);
                        rnd = func_203b990(gRandState);
                        rnd = ((((0x7fff & (rnd >> 16)) << 12) >> 15) - 0x800);
                        func_203d388(&sum, (s16)rnd);
                    }
                    else if (fC)
                    {
                        s32 rnd;
                        vy = (s32)(((s64)vx * 0x1a00 + 0x800) >> 12);
                        rnd = func_203b990(gRandState);
                        rnd = ((0x7fff & (rnd >> 16)) << 12) >> 15 << 12 >> 6;
                        vy = vy + rnd;
                        if (o->posx < 0x18000)
                        {
                            if (sum.y > 0)
                            {
                                sum.x = 0;
                                sum.y = 0x1000;
                            }
                        }
                    }
                    else
                    {
                        vy = (s32)(((s64)vx * 0x1200 + 0x800) >> 12);
                    }
                    (void)g;
                    {
                        s64 dvx = ((s64)vy * sum.x + 0x800) >> 12;
                        s64 dvy = ((s64)vy * sum.y + 0x800) >> 12;
                        o->velx -= (s32)dvx;
                        o->vely -= (s32)dvy;
                    }
                }
            }
        }

        acc += 0x80;
        loops += 1;
    } while (mode == 1 && loops < 0x21 && acc <= savevx);

    if (fB == 1)
    {
        if (o->posx < 0xd0000)
            return 1;
        if (o->posx < 0xd8000)
        {
            o->posx = 0xd8000;
            return 1;
        }
        if (o->posx < 0xe8000)
            o->posx = 0xe8000;
        {
            Vec2 p;
            st = o->stage;
            func_211470c(&p, (0 < st->n66c) ? st->arr684[0] : 0);
            o->posy = (p.y + ~0x20000) - o->f28;
        }
        {
            Vec2 p;
            st = o->stage;
            func_21146f4(&p, (0 < st->n66c) ? st->arr684[0] : 0);
            if (p.y < -0x1000)
                return 1;
        }
        {
            Vec2 p;
            st = o->stage;
            func_21146f4(&p, (0 < st->n66c) ? st->arr684[0] : 0);
            if (o->vely < p.y)
                return 1;
            o->velx = 0;
        }
        {
            Vec2 p;
            st = o->stage;
            func_21146f4(&p, (0 < st->n66c) ? st->arr684[0] : 0);
            o->vely = p.y;
            if (o->vely < -0x6000)
                o->vely = (((o->vely + 0x6000) >> 2) - 0x6000);
        }
        if (o->f124 == 0)
        {
            if (o->vely < -0x6000)
            {
                func_2012718(gSndA, o->posx);
                func_2012718(gSndB, o->posx);
            }
            else
            {
                s32 v = (s32)(((s64)(-o->vely << 7) * gMulK) >> 12) + ((-o->vely << 7) >> 31);
                if (v > 0x7f) v = 0x7f;
                if (v < 0) v = 0;
                func_20126ac(gSndC, 5, v, func_20126e8(o->posx) ? 0 : 0);
                if (v >= 0x40)
                    func_20126ac(gSndD, 5, v, func_20126e8(o->posx) ? 0 : 0);
            }
            o->f124 = 5;
        }
        if (o->f128 == 0)
        {
            if (o->vely < -0x6000)
                func_2012718(gSndA, o->posx);
            o->f128 = 1;
            return 1;
        }
        return 1;
    }

    if (fA == 1)
    {
        Vec2 t;
        t.x = savevx;
        t.y = savevy;
        func_2111b90(o, &t, gTabA);
    }
    else if (fB == 1)
    {
        Vec2 t;
        t.x = savevx;
        t.y = savevy;
        func_2111b90(o, &t, gTabB);
    }
    else if (fC == 1)
    {
        Vec2 t;
        t.x = savevx;
        t.y = savevy;
        func_2111b90(o, &t, gTabC);
    }
    else if (fE == 1)
    {
        Vec2 t;
        t.x = savevx;
        t.y = savevy;
        func_2111b90(o, &t, gTabD);
    }

    {
        s32 j;
        s64 r2 = ((s64)(o->f28 + 0x10000) * (o->f28 + 0x10000) + 0x800) >> 12;
        st = o->stage;
        for (j = 0; j < st->n66c; j++)
        {
            struct Sub *sub = (j < st->n66c) ? st->arr720[j] : 0;
            if (!func_21115c4(sub))
            {
                Vec2 base, dif, dif2;
                s32 r4v;
                base.x = o->posx;
                base.y = o->posy;
                sub = (j < st->n66c) ? st->arr720[j] : 0;
                func_211470c(&dif, sub);
                dif.x = base.x - dif.x;
                dif.y = base.y - dif.y;
                dif.x = dif.y * 2;
                if ((s64)func_203d5bc((Vec2 *)&dif) >= r2)
                    continue;
                r4v = (o->f28 + 0x10000) - func_203d614(&dif);
                if (o->f28 >= r4v)
                {
                    dif2 = dif;
                    func_203d434(&dif2);
                    o->velx = (s32)(((s64)dif2.x * r4v + 0x800) >> 12);
                    o->vely = (s32)(((s64)dif2.y * r4v + 0x800) >> 12);
                    o->posx -= (o->velx >> 6) >> 6;
                    o->posy -= o->vely >> 6;
                    (void)dif2;
                }
                else
                {
                    sub = (j < st->n66c) ? st->arr720[j] : 0;
                    func_211470c(&base, sub);
                    o->f44 = base.x;
                    o->f48 = base.y;
                    sub = (j < st->n66c) ? st->arr720[j] : 0;
                    func_21115cc(sub);
                    func_2111dcc(o, 0x80);
                    o->f3a = 1;
                    return 1;
                }
            }
        }
    }

    (void)fD;
    return 0;
}
