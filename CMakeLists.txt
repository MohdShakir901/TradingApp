cmake_minimum_required(VERSION 3.20)

project(TradingApplication)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(TradingApplication
    src/main.cpp
    src/Account.cpp
    src/Stock.cpp
    src/Holding.cpp
    src/Portfolio.cpp
    src/Transaction.cpp
    src/TransactionHistory.cpp
    src/StockMarket.cpp
)

target_include_directories(TradingApplication PRIVATE
    include
)