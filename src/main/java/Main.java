

public class Main {

    // Load the native library
    static {
        System.loadLibrary("NativeLib");
    }

    // Declare the native method
    public native void sayHello();

    public static void main(String[] args) {
        // Create an instance of the Main class
        Main main = new Main();

        // Call the native method
        main.sayHello();

        try (PersonNative person = new PersonNative("Sam", "Nelson", "12 @ Mars", 31)) {
            // Use the person object
            System.out.println(person.toString());
        }  // person.close() is called automatically here

    }
}
