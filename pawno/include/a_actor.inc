/*  SA-MP Actor Functions
 *
 *  (c) Copyright 2015, SA-MP Team
 *
 */

#if defined _actor_included
	#endinput
#endif
#define _actor_included
#pragma library actors

native CreateActor(const modelid, const Float:X, const Float:Y, const Float:Z, const Float:Rotation);
native DestroyActor(actorid);

native IsActorStreamedIn(actorid, forplayerid);

native SetActorVirtualWorld(actorid, vworld);
native GetActorVirtualWorld(actorid);

native ApplyActorAnimation(const actorid, const animlib[], const animname[], const Float:fDelta, const loop, const lockx, const locky, const freeze, const time);
native ClearActorAnimations(actorid);

native SetActorPos(actorid, Float:X, Float:Y, Float:Z);
native GetActorPos(actorid, &Float:X, &Float:Y, &Float:Z);
native SetActorFacingAngle(actorid, Float:ang);
native GetActorFacingAngle(actorid, &Float:ang);

native SetActorHealth(actorid, Float:health);
native GetActorHealth(actorid, &Float:health);
native SetActorInvulnerable(actorid, invulnerable = true);
native IsActorInvulnerable(actorid);

native IsValidActor(actorid);
