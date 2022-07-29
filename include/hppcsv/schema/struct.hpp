////////////////////////////////////////////////////////////////////////////////
//
// Schema Data Struct
//
////////////////////////////////////////////////////////////////////////////////
#undef HPPCSV_SCHEMA
#undef HPPCSV_COL

#define HPPCSV_SCHEMA(SCHEMA_NAME, COLS...)        \
  struct SCHEMA_NAME {                          \
    COLS                                        \
  };

#define HPPCSV_COL(CPPTYPE, CPPNAME, CSVNAME...) \
  CPPTYPE CPPNAME;

