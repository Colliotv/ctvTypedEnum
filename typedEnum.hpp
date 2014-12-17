#include <set>
#include <algorithm>

template <typename __enum, typename __enum_type = int>
class Enum {
public:
  using instance_list = typename std::set<__enum_type>;
  using iterator = typename instance_list::iterator;
  using enum_type = __enum_type;

protected:
  static instance_list m_instance;
  enum_type             m_value;

protected:
  Enum(__enum_type t_value) : m_value(t_value)
  { m_instance.emplace(m_value);}
  Enum() : m_value(m_instance.size() ? *m_instance.rbegin() + 1 : 0)
  { m_instance.emplace(m_value);}

public:
  operator __enum_type () const { return m_value; }
  bool operator == (const __enum_type& t_oth) const { return m_value == t_oth}

public:
  static iterator begin() { return m_instance.begin(); }
  static iterator end() { return m_instance.end(); }
};

template<typename __enum, typename __enum_type>
typename Enum<__enum, __enum_type>::instance_list Enum< __enum, __enum_type >::m_instance({});

