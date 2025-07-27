

int main() {
    int n, capacity;
    std::cout << "Enter number of books: ";
    std::cin >> n;
    std::cout << "Enter capacity (max expenditure): ";
    std::cin >> capacity;

    std::vector<Book> books(n);
    for (int i = 0; i < n; i++) {
        std::cout << "Enter price and pages for book " << i + 1 << ": ";
        std::cin >> books[i].price >> books[i].pages;
    }

    fractionalKnapsack(books, capacity);

    return 0;
}