ctvTypedEnum
============

Very small library to allow Typed Enum and iterating throught it

Utilisation Example:

class my_enum : Enum<my_enum, type/* wanted type (int by default)*/> {
private:
  my_enum(type value) : Enum<my_enum, type>(value) {}
public:
  static const my_enum value1;
  static const my_enum value2;
}

template<> // enable enum instance
typename Enum<my_enum, const char*>::instance_list Enum<my_enum, const char*>::m_instance({});

// define enum values
const my_enum my_enum::value1("enum 1");
const my_enum my_enum::value2("enum 2");

int main() {
  my_enum var1 = my_enum::value1;
  if (var1 == "enum 1") std::cout << "well that work" << std::endl;
}
