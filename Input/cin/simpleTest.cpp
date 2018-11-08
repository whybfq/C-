void testInput() {
    string str;
    cout << "cin test " << endl;
    cin >> str;

    cout << str << endl;
    cin.sync();
    cin >> str;
    cout << str << endl;
}

void inputTest2() {
    char ch1,ch2;
    cout << "input two strings: " << endl;
    cin.get(ch1);
    cin.get(ch2);
    cout << "the two strings are: " << endl;
    cout << ch1 << endl;
    cout << ch2 << endl;
    cout << (int)ch1 << " " << (int)ch2 << endl;
}
