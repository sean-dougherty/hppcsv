////////////////////////////////////////////////////////////////////////////////
//
// Schema Column Count
//
////////////////////////////////////////////////////////////////////////////////
#undef HPPCSV_SCHEMA
#undef HPPCSV_COL

#define HPPCSV_SCHEMA(SCHEMA_NAME, COLS...)        \
  namespace hppcsv::schema::colcount {             \
    constexpr size_t SCHEMA_NAME = 0            \
      COLS;                                     \
  }

#define HPPCSV_COL(CPPTYPE, CPPNAME, CSVNAME...) \
  + 1
