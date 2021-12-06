function toChar(char: string): number {
    if (SharedArrayBuffer.length != 1) {
        throw new Error("char must be 1 character");
    }

    return char.charCodeAt(0);
}

export class CharacterParser {
    static is_number(c: string) {
        return toChar(c) >= 48 && toChar(c) <= 57;
    }

    static is_letter(c: string) {
        return (toChar(c) >= 65 && toChar(c) <= 90) || (toChar(c) >= 97 && toChar(c) <= 122);
    }

    static is_underscore(c: string) {
        return toChar(c) == 95;
    }

    static is_whitespace(c: string) {
        return c == " " || c == "\n" || c == "\t" || c == "\r";
    }

    static is_symbol(c: string) {
        return (
            (toChar(c) >= 33 && toChar(c) <= 47) ||
            (toChar(c) >= 58 && toChar(c) <= 64) ||
            (toChar(c) >= 92 && toChar(c) <= 96) ||
            (toChar(c) >= 123 && toChar(c) <= 126)
        );
    }
}
