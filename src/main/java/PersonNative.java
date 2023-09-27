public class PersonNative implements AutoCloseable {
  private long nativeHandle;  // nativeHandle stores the memory address of the native object

  private native void initNativeObject(String firstName, String lastName, String address, int age);
  private native void disposeNativeObject();

  // Constructor
  public PersonNative(String firstName, String lastName, String address, int age) {
    initNativeObject(firstName, lastName, address, age);
  }

  // Native method declarations
  public native String getFirstName();
  public native String getLastName();
  public native String getAddress();
  public native int getAge();
  public native String toString();

  // Implement the close method to clean up native resources
  @Override
  public void close() {
    disposeNativeObject();
  }
}
