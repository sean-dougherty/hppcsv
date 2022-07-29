////////////////////////////////////////////////////////////////////////////////
//
// Schema Reader::read_row()
//
////////////////////////////////////////////////////////////////////////////////
#undef HPPCSV_SCHEMA
#undef HPPCSV_COL

#define HPPCSV_SCHEMA(SCHEMA_NAME, COLS...)                        \
  namespace hppcsv::schema {                                       \
                                                                \
  template<typename csv_reader_t>                                         \
    bool SCHEMA_NAME##_read_row(csv_reader_t& reader, SCHEMA_NAME& schema) {       \
    return detail::read_row(reader COLS);                               \
    }                                                           \
  }

#define HPPCSV_COL(CPPTYPE, CPPNAME, CSVNAME...)   \
  , schema.CPPNAME

