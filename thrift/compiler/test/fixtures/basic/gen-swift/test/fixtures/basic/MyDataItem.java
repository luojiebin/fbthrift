/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

package test.fixtures.basic;

import com.facebook.swift.codec.*;
import com.facebook.swift.codec.ThriftField.Requiredness;
import com.facebook.swift.codec.ThriftField.Recursiveness;
import java.util.*;

import static com.google.common.base.MoreObjects.toStringHelper;

@SwiftGenerated
@ThriftStruct(value="MyDataItem", builder=MyDataItem.Builder.class)
public final class MyDataItem {
    @ThriftConstructor
    public MyDataItem(
    ) {
    }
    
    
    
    public static class Builder {
    
        public Builder() { }
        public Builder(MyDataItem other) {
        }
    
        @ThriftConstructor
        public MyDataItem build() {
            return new MyDataItem (
            );
        }
    }
    


    @Override
    public String toString() {
        return toStringHelper(this)
            .toString();
    }
    
    @Override
    public boolean equals(Object o) {
        if (this == o) {
            return true;
        }
        if (o == null || getClass() != o.getClass()) {
            return false;
        }
    
        MyDataItem other = (MyDataItem)o;
    
        return
            true;
    }
    
    @Override
    public int hashCode() {
        return Arrays.deepHashCode(new Object[] {
        });
    }
    
}
