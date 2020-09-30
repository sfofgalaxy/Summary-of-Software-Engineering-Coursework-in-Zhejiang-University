#include <iostream>
using namespace std;

class Stock
{
public:
  Stock(const string& symbol, const string& name)
  {
    this->symbol = symbol;
    this->name = name;
  }

  string getSymbol() const
  {
    return symbol;
  }

  string getName() const
  {
    return name;
  }

  double getPreviousClosingPrice() const
  {
    return previousClosingPrice;
  }

  double getCurrentPrice() const
  {
    return currentPrice;
  }

  void setSymbol(const string& symbol) 
  {
    this->symbol = symbol;
  }

  void setName(const string& name)
  {
    this->name = name;
  }

  void setPreviousClosingPrice(double price)
  {
    this->previousClosingPrice = price;
  }

  void setCurrentPrice(double price)
  {
    this->currentPrice = price;
  }

  double getChangePercent()
  {
    return (currentPrice - previousClosingPrice) / previousClosingPrice;
  }

private:
  string symbol;
  string name;
  double previousClosingPrice;
  double currentPrice;
};

int main()
{
  Stock stock("MSFT", "Microsoft Coorporations");
  stock.setPreviousClosingPrice(27.5);

  // Set current price
  stock.setCurrentPrice(27.6);

  // Display stock info
  cout << "Previous Closing Price: " <<
    stock.getPreviousClosingPrice() << endl;
  cout << "Current Price: " <<
    stock.getCurrentPrice() << endl;
  cout << "Percentage Change: " <<
    stock.getChangePercent() << endl;

  return 0;
}


