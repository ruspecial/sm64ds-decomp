int func_ov095_021358cc(int a, short* pos, short* vel, int target, short thresh, int accel, short mult)
{
    short old = *pos;
    *pos = old + *vel;
    short now = *pos;
    if (now == target
        || ((now - target) * (old - target) < 0
            && *vel > -thresh && *vel < thresh)) {
        *pos = target;
        *vel = 0;
        return 1;
    }
    if (now >= target)
        accel = (short)-accel;
    if ((short)*vel * (short)accel < 0)
        accel = (short)accel * (short)mult;
    *vel = *vel + accel;
    return 0;
}
