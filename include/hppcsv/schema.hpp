#pragma once

namespace hppcsv::schema {

  template<
    typename schema_type,
    typename trim_policy = hppcsv::trim_chars<' ', '\t'>,
    typename quote_policy = hppcsv::double_quote_escape<',','"'>,
    typename overflow_policy = hppcsv::throw_on_overflow,
    typename comment_policy = hppcsv::no_comment
    >
  struct Reader {
    Reader(const std::string& path, hppcsv::ignore_column ignore_policy = hppcsv::ignore_extra_column);
    bool read_row(schema_type& schema);
  };
  
};

namespace hppcsv::schema::detail {
  std::string csvname(const std::string& cppname) {return cppname;}
  std::string csvname(const std::string&, const std::string& csvname) {return csvname;}

  template<typename csv_reader_t,
           typename... cols_t>
  bool read_row(csv_reader_t& reader, cols_t&... cols) {
    return reader.read_row(cols...);
  }
}
