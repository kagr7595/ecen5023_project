#ifndef __NMEA_H__
#define __NMEA_H__

#define GGA "GPGGA" //Global Positioning System Fix Data
    #define UTC_TIME        1
    #define LATITUDE        2
    #define NS_INDICATOR    3
    #define LONGITUDE       4
    #define EW_INDICATOR    5
    #define GPS_QUALITY     6
    #define SATILITES_USED  7
    #define HDOP            8
    #define ALTITUDE        9
    #define DGPS_STATION_ID 10
    #define CHECKSUM        11

#define GLL "GPGLL" //Latitude/Longitude
#define GSA "GPGSA" //GNSS DOP and Active Satellites
#define GSV "GPGSV" //GNSS Satellites in View
#define RMC "GPRMC" //Recommended Minimum Specific GNSS Data
#define VTG "GPVTG" //Course Over Ground and Ground Speed

typedef struct {
    char latitude[10];
    char longitude[10];
    char altitude[7];
} nmea_gps_coords;

nmea_gps_coords* nmea_parse_coords(char* nmea_string);



#endif
