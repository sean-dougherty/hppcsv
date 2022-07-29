#////////////////////////////////////////////////////////////////////////////////
//
// Schema Reader Specialization
//
////////////////////////////////////////////////////////////////////////////////
#undef HPPCSV_SCHEMA
#undef HPPCSV_COL

#define HPPCSV_SCHEMA(SCHEMA_NAME, COLS...)                                \
namespace hppcsv::schema {                                               \
  template<                                                             \
    typename trim_policy,  \
    typename quote_policy, \
    typename overflow_policy, \
    typename comment_policy \
    >                                                                   \
  struct Reader<                                                 \
    SCHEMA_NAME,\
    trim_policy,\
    quote_policy,\
    overflow_policy,\
    comment_policy \
  > \
  { \
  private:                                                              \
      using csv_reader_t = hppcsv::CSVReader<                                   \
        hppcsv::schema::colcount::SCHEMA_NAME, \
        trim_policy,                                                      \
        quote_policy,                                                     \
        overflow_policy,                                                  \
        comment_policy                                                    \
      >;                                                                \
                                                                        \
      csv_reader_t csv_reader;                                          \
                                                                        \
  public:                                                               \
    Reader(const std::string& path,                                     \
           hppcsv::ignore_column ignore_policy = hppcsv::ignore_extra_column)   \
      : csv_reader(path.c_str())                                        \
    {                                                                   \
      csv_reader.read_header(ignore_policy COLS);                               \
    }                                                                   \
                                                                        \
    bool read_row(SCHEMA_NAME& schema) {                                \
      return SCHEMA_NAME##_read_row(csv_reader, schema);                \
    }                                                                   \
                                                                        \
  };                                            \
}

#define HPPCSV_COL(CPPTYPE, CPPNAME, CSVNAME...)   \
  , hppcsv::schema::detail::csvname(#CPPNAME, ##CSVNAME)

