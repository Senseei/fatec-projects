package fatec.java.numeric_converter;

import java.util.function.Consumer;

public class NumericConverter {

    // This ensure this will not be instatiated
    private NumericConverter() {}

    // Numeric Converter, be sure to insert the right numeric base to precise conversion!

    public static void main(String... args) {
        String binary = "1010";
        long decimal = 16;
        String octal = "10";
        String hexadecimal = "10";

        Consumer<String> consumer = x -> System.out.println(x);

        System.out.println("\nBinary... ");
        print(consumer, "To octal: " + Binary.toOctal(binary));
        print(consumer, "To decimal: " + Binary.toDecimal(binary));
        print(consumer, "To hexadecimal: " + Binary.toHexadecimal(binary));
        System.out.println();

        System.out.println("Octal... ");
        print(consumer, "To binary: " + Octal.toBinary(octal));
        print(consumer, "To Decimal: " + Octal.toDecimal(octal));
        print(consumer, "To hexadecimal: " + Octal.toHexadecimal(octal));
        System.out.println();

        System.out.println("Decimal... ");
        print(consumer, "To binary: " + Decimal.toBinary(decimal));
        print(consumer, "To Octal: " + Decimal.toOctal(decimal));
        print(consumer, "To Hexadecimal: " + Decimal.toHexadecimal(decimal));
        System.out.println();

        System.out.println("Hexadecimal... ");
        print(consumer, "To binary: " + Hexadecimal.toBinary(hexadecimal));
        print(consumer, "To octal: " + Hexadecimal.toOctal(hexadecimal));
        print(consumer, "To decimal: " + Hexadecimal.toDecimal(hexadecimal));
        System.out.println();
    }
    
    public static long toDecimal(String numToConvert, int base) {
        if (numToConvert == null)
            throw new IllegalArgumentException("num argument cannot be null");

        String num = numToConvert.toUpperCase();
        int sum = 0;
        
        for (int i = 0, length = num.length(); i < length; i++) {
            int digit = num.charAt(length - i - 1);
            if (Character.isAlphabetic(digit)) {
                sum += (10 + digit - 'A') * Math.pow(base, i);
            }
            else if (Character.isDigit(digit)) {
                digit = Character.getNumericValue(digit);
                sum += digit * Math.pow(base, i);
            }
        }
        return sum;
    }

    public static void print(Consumer<String> consumer, String value) {
        consumer.accept(value);
    }
}
