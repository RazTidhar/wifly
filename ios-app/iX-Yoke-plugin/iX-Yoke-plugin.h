/*
 *  iX-Yoke-plugin.h
 *  iX-Yoke-plugin
 *
 *  Created by Daniel Dickison on 5/9/09.
 *  Copyright 2009 Daniel_Dickison. All rights reserved.
 *
 */


#ifndef __IX_YOKE_PLUGIN_H
#define __IX_YOKE_PLUGIN_H

#include <stdio.h>
#include <pthread.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>

#include "XPLMPlugin.h"
#include "XPLMDataAccess.h"
#include "XPLMProcessing.h"
#include "XPLMUtilities.h"
#include "XPWidgetDefs.h"
#include "XPWidgets.h"
#include "XPWidgetUtils.h"
#include "XPStandardWidgets.h"
#include "XPWidgetsEx.h"
#include "XPLMMenus.h"


#include "iX_Yoke_Network.h"


#if APL
int MacToUnixPath(const char * inPath, char * outPath, int outPathMaxLen);
#endif

void debug(char *str);


void *server_loop(void *arg);
extern pthread_t server_thread;
extern char *server_msg;



// The display strings corresponding to iXControlType.
#define axis_choices "Off;Pitch;Roll;Yaw;Roll and Yaw;Throttle;Prop Pitch"

typedef enum {
    kAxisControlOff = 0,
    kAxisControlPitch,
    kAxisControlRoll,
    kAxisControlYaw,
    kAxisControlRollAndYaw,
    kAxisControlThrottle,
    kAxisControlPropPitch
} iXControlType;


typedef struct {
    iXControlType type;
    float value;
    float min;
    float max;
    
    // UI stuff
    const char title[32];
    XPWidgetID popup_widget;
    XPWidgetID min_widget;
    XPWidgetID max_widget;
    XPWidgetID progress_widget;
    XPWidgetID reverse_widget;
} iXControlAxis;

typedef iXControlAxis * iXControlAxisRef;


typedef enum {
    kAxisTiltX = 0,
    kAxisTiltY,
    kAxisTouchX,
    kAxisTouchY,
    kNumAxes
} iXControlAxisID;



iXControlAxisRef get_axis(iXControlAxisID axis_id);



// Prefs and Presets

void load_prefs();
void save_prefs();
int get_preset_names(char **outNames);
int current_preset(); // Returns -1 for "Custom".
void set_current_preset(int i); // Pass -1 for "Custom".
void save_preset_as(const char *inName);
void delete_preset(int i);


// Window

void show_window();
void destroy_window();
int update_window();



#endif
