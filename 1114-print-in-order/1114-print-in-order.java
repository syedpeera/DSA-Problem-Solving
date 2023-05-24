class Foo {
    private CountDownLatch latchAfterFirst;
    private CountDownLatch latchAfterSecond;
    public Foo() {
        latchAfterFirst = new CountDownLatch(1);
        latchAfterSecond = new CountDownLatch(1);
    }

    public void first(Runnable printFirst) throws InterruptedException {

        // printFirst.run() outputs "first". Do not change or remove this line.
        printFirst.run();
        latchAfterFirst.countDown();
    }

    public void second(Runnable printSecond) throws InterruptedException {
        latchAfterFirst.await();
        // printSecond.run() outputs "second". Do not change or remove this line.
        printSecond.run();
        latchAfterSecond.countDown();
    }

    public void third(Runnable printThird) throws InterruptedException {
        latchAfterSecond.await();
        // printThird.run() outputs "third". Do not change or remove this line.
        printThird.run();
    }
}