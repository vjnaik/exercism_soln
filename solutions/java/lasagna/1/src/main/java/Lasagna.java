public class Lasagna {

    public int expectedMinutesInOven() {
        return 40;
    }

    public int remainingMinutesInOven(int t) {
        return expectedMinutesInOven() - t;
    }

    public int preparationTimeInMinutes(int layer) {
        return 2 * layer;
    }

    public int totalTimeInMinutes(int layer, int t) {
        return preparationTimeInMinutes(layer) + t;
    }
}