const MAXFACILITIES = 10;
const MAXLEVELS = 8;
const MAXMSG    = 1024;

typedef string text<MAXMSG>;

struct eventsislog {
   int facility;
   int level;
   text msg;
};

struct faclevel {
   int facility;
   int level;
};

union Result switch (int type){  /* Success or failure? */
   case 0: int value;               /* Result in case of success */
   case 1: text msg;               /* Message in case of error */
};

program SISLOG{
    version FIRST{
        Result initialize_sislog(faclevel)=1;
        Result log_event(eventsislog)=2;
        Result get_total_facilities(int)=3;
        Result get_total_level(int)=4;
        Result get_total_facility_level(faclevel)=5;
        Result get_num_facilities(void)=6;
        Result get_num_levels(void)=7;
        Result get_facile_name(int)=8;
        Result get_level_name(int)=9;
    }=1;
}=0x2022f001;

