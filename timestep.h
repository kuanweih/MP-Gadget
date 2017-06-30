#ifndef TIMESTEP_H
#define TIMESTEP_H

#include "allvars.h"
/*Flat array containing all active particles:
set in run.c: find_next_sync_point_and_drift*/
extern int NumActiveParticle;
extern int *ActiveParticle;

extern int TimeBinCount[TIMEBINS];
extern int TimeBinCountSph[TIMEBINS];

void timestep_allocate_memory(int MaxPart);
int find_active_timebins(int next_kick);
void rebuild_activelist(void);
void set_global_time(double newtime);
void advance_and_find_timesteps(void);
int find_dti_displacement_constraint(void);
double find_dloga_displacement_constraint(void);
int is_timebin_active(int i);

static inline double get_dloga_for_bin(int timebin)
{
    return (timebin ? (1 << timebin) : 0 ) * All.Timebase_interval;
}
#endif