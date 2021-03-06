/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#pragma once

#include <thrift/lib/cpp2/gen/module_data_h.h>

#include "thrift/compiler/test/fixtures/mcpp2-compare/gen-cpp2/module_types.h"

namespace some { namespace valid { namespace ns {

struct _MyEnumAEnumDataStorage {
  using type = MyEnumA;
  static constexpr const std::size_t size = 3;
  static constexpr const std::array<MyEnumA, 3> values = {{
    MyEnumA::fieldA,
    MyEnumA::fieldB,
    MyEnumA::fieldC,
  }};
  static constexpr const std::array<folly::StringPiece, 3> names = {{
    "fieldA",
    "fieldB",
    "fieldC",
  }};
};

}}} // some::valid::ns
namespace apache { namespace thrift {

template <> struct TEnumDataStorage<::some::valid::ns::MyEnumA> {
  using storage_type = ::some::valid::ns::_MyEnumAEnumDataStorage;
};

}} // apache::thrift
namespace some { namespace valid { namespace ns {

struct _AnnotatedEnumEnumDataStorage {
  using type = AnnotatedEnum;
  static constexpr const std::size_t size = 3;
  static constexpr const std::array<AnnotatedEnum, 3> values = {{
    AnnotatedEnum::FIELDA,
    AnnotatedEnum::FIELDB,
    AnnotatedEnum::FIELDC,
  }};
  static constexpr const std::array<folly::StringPiece, 3> names = {{
    "FIELDA",
    "FIELDB",
    "FIELDC",
  }};
};

}}} // some::valid::ns
namespace apache { namespace thrift {

template <> struct TEnumDataStorage<::some::valid::ns::AnnotatedEnum> {
  using storage_type = ::some::valid::ns::_AnnotatedEnumEnumDataStorage;
};

}} // apache::thrift
namespace some { namespace valid { namespace ns {

struct _AnnotatedEnum2EnumDataStorage {
  using type = AnnotatedEnum2;
  static constexpr const std::size_t size = 3;
  static constexpr const std::array<AnnotatedEnum2, 3> values = {{
    AnnotatedEnum2::FIELDA,
    AnnotatedEnum2::FIELDB,
    AnnotatedEnum2::FIELDC,
  }};
  static constexpr const std::array<folly::StringPiece, 3> names = {{
    "FIELDA",
    "FIELDB",
    "FIELDC",
  }};
};

}}} // some::valid::ns
namespace apache { namespace thrift {

template <> struct TEnumDataStorage<::some::valid::ns::AnnotatedEnum2> {
  using storage_type = ::some::valid::ns::_AnnotatedEnum2EnumDataStorage;
};

}} // apache::thrift
namespace some { namespace valid { namespace ns {

struct _MyEnumBEnumDataStorage {
  using type = MyEnumB;
  static constexpr const std::size_t size = 1;
  static constexpr const std::array<MyEnumB, 1> values = {{
    MyEnumB::AField,
  }};
  static constexpr const std::array<folly::StringPiece, 1> names = {{
    "AField",
  }};
};

}}} // some::valid::ns
namespace apache { namespace thrift {

template <> struct TEnumDataStorage<::some::valid::ns::MyEnumB> {
  using storage_type = ::some::valid::ns::_MyEnumBEnumDataStorage;
};

}} // apache::thrift

