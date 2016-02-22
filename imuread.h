#ifndef IMUread_h_
#define IMUread_h_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdarg.h>
#include <string.h>
#include <math.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#if defined(LINUX)
  #include <termios.h>
  #include <unistd.h>
  #include <GL/gl.h>
  #include <GL/glu.h>
#elif defined(WINDOWS)
  #include <windows.h>
  #include <GL/gl.h>
  #include <GL/glu.h>
#elif defined(MACOSX)
  #include <termios.h>
  #include <unistd.h>
  #include <OpenGL/gl.h>
  #include <OpenGL/glu.h>
#endif


#if defined(LINUX)
  #define PORT "/dev/ttyACM0"
#elif defined(WINDOWS)
  #define PORT "COM3"
#elif defined(MACOSX)
  #define PORT "/dev/cu.usbmodemfd132"
#endif

#define TIMEOUT_MSEC 40

#define MAGBUFFSIZEX 14
#define MAGBUFFSIZEY 28
#define MAGBUFFSIZE (MAGBUFFSIZEX * MAGBUFFSIZEY)

#ifdef __cplusplus
extern "C"{
#endif

typedef struct {
	float x;
	float y;
	float z;
	int valid;
} magdata_t;
extern magdata_t caldata[MAGBUFFSIZE];
extern magdata_t hard_iron;
extern float soft_iron[9];
typedef struct {
	float w;
	float x;
	float y;
	float z;
} quat_t;
extern quat_t current_orientation;

extern int open_port(const char *name);
extern int read_serial_data(void);
extern void close_port(void);
void visualize_init(void);
void display_callback(void);
void resize_callback(int width, int height);

#ifdef __cplusplus
} // extern "C"
#endif

#endif
