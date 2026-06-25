# 🏦 Bank System with Currency Exchange

A fully-featured, console-based **Bank Management System** built in **C++** using **Object-Oriented Programming** principles. The system supports complete client and user management, financial transactions, a login audit register, and a live currency exchange module — all backed by flat-file persistent storage.

> Demonstrates real-world OOP design patterns in C++.

---

## 📋 Table of Contents

- [Project Overview](#-project-overview)
- [Features](#-features)
- [Currency Exchange Module](#-currency-exchange-module)
- [Technologies Used](#-technologies-used)
- [OOP Concepts Applied](#-oop-concepts-applied)
- [Project Structure](#-project-structure)
- [Data Storage](#-data-storage)
- [Permission System](#-permission-system)
- [How to Run](#-how-to-run)
- [Example Workflow](#-example-workflow)
- [Modules Overview](#-modules-overview)
- [Future Improvements](#-future-improvements)
- [Author](#-author)

---

## 🔍 Project Overview

This project simulates a real banking environment where system **users** (bank employees) log in with credentials, and depending on their assigned permissions, they can manage **clients**, perform **financial transactions**, administer other **users**, and perform **currency exchange** operations.

The system enforces role-based access control: every screen checks whether the currently logged-in user has the required permission before displaying any content. Passwords are encrypted before being stored to disk.

---

## ✨ Features

### 🔐 Authentication
- Secure login screen with **username and password** validation
- **3-attempt lockout** — the system blocks access after 3 consecutive failed login attempts
- Passwords are **encrypted** on disk using a Caesar-cipher shift
- Every successful login is recorded in the **Login Register** with a timestamp

### 👥 Client Management
| Feature | Description |
|---|---|
| List Clients | View all bank clients in a formatted table |
| Add New Client | Register a new client with account number, PIN, and balance |
| Delete Client | Remove a client with confirmation prompt |
| Update Client | Edit any client's personal or account information |
| Find Client | Search for a client by account number |

### 💰 Transactions
| Feature | Description |
|---|---|
| Deposit | Add funds to any client account |
| Withdraw | Withdraw funds with insufficient-balance protection |
| Transfer | Move funds between two accounts; logs every transfer |
| Transfer Log | View a full history of all transfers with balances |
| Total Balances | Display all account balances with a grand total in words |

### 👤 User Management *(Admin only)*
| Feature | Description |
|---|---|
| List Users | View all system users and their permissions |
| Add New User | Create a user with a custom permission set |
| Delete User | Remove a user from the system |
| Update User | Edit user info and reassign permissions |
| Find User | Search for a user by username |

### 📋 Login Register
- View a complete log of every login attempt in the system
- Displays date/time, username, encrypted password, and permissions at login time

---

## 💱 Currency Exchange Module

A self-contained currency exchange system supporting **180+ world currencies**.

| Feature | Description |
|---|---|
| List Currencies | Browse all currencies with country, code, name, and USD rate |
| Find Currency | Search by currency **code** (e.g. `EUR`) or **country name** |
| Update Rate | Edit the exchange rate for any currency |
| Currency Calculator | Convert any amount between **any two currencies** via USD as a base |

**How conversion works:**
1. Convert the source amount → USD (divide by source rate)
2. Convert USD → target currency (multiply by target rate)

The calculator supports **repeated calculations** in a single session without going back to the menu.

---

## 🛠️ Technologies Used

- **Language:** C++ (C++11 or later)
- **Paradigm:** Object-Oriented Programming (OOP)
- **IDE:** Microsoft Visual Studio (`.sln` solution file included)
- **Storage:** Plain text flat files (no database required)
- **Standard Libraries:** `<iostream>`, `<fstream>`, `<vector>`, `<string>`, `<iomanip>`, `<ctime>`

---

## 🧱 OOP Concepts Applied

| Concept | Where It's Used |
|---|---|
| **Encapsulation** | All class fields are `private`; accessed through `get/set` properties (`__declspec(property)`) |
| **Inheritance** | `clsBankClient` and `clsUser` both inherit from `clsPerson`; all screen classes inherit from `clsScreen` |
| **Abstraction** | `clsScreen` hides the `_DrawScreenHeader()` and `CheckAccessRights()` logic from all screens |
| **Static Methods** | File I/O, Find, and List operations are `static` — called without instantiating objects |
| **Enumerations** | `enMode` (Empty/Add/Update), `enPermissions` (bitmask), menu option enums in every screen |
| **Structs** | `stTransferLogRecord` and `stLoginRegisterRecord` for structured log data |
| **Operator Overloading** | Bitmask OR (`|=`) used to combine permission flags |
| **Templates** | `clsInputValidate::ReadNumber<T>()` and `ReadNumberBetween<T>()` work for any numeric type |
| **Composition** | `clsBankClient` embeds transfer log logic; `clsUser` embeds login register logic |
| **Mode Pattern** | Objects carry their own `_Mode` (EmptyMode / AddNewMode / UpdateMode) to control `Save()` behavior |

---

## 📁 Project Structure

```
Bank-System-with-Currency-Exchange/
│
├── 📄 Bank_System.sln              # Visual Studio solution file
│
├── 🔷 Core Business Classes
│   ├── clsPerson.h                 # Base class: FirstName, LastName, Email, Phone
│   ├── clsBankClient.h             # Client entity: CRUD, Deposit, Withdraw, Transfer
│   ├── clsUser.h                   # User entity: CRUD, Permissions, Login Register
│   └── clsCurrency.h               # Currency entity: Find, Rate, Conversion logic
│
├── 🖥️ Screen Classes (UI Layer)
│   ├── clsScreen.h                 # Base screen: header drawing, access rights check
│   ├── clsLoginScreen.h            # Login with lockout
│   ├── clsMainScreen.h             # Main menu (10 options)
│   │
│   ├── 👤 Client Screens
│   │   ├── clsClientListScreen.h
│   │   ├── clsAddNewClientScreen.h
│   │   ├── clsDeleteClientScreen.h
│   │   ├── clsUpdateClientScreen.h
│   │   └── clsFindClientScreen.h
│   │
│   ├── 💰 Transaction Screens
│   │   ├── clsTransactionsScreen.h     # Transactions submenu
│   │   ├── clsDepositScreen.h
│   │   ├── clsWithdrawScreen.h
│   │   ├── clsTransferScreen.h
│   │   ├── clsTransferLogScreen.h
│   │   └── clsTotalBalancesScreen.h
│   │
│   ├── 👥 User Management Screens
│   │   ├── clsManageUsers.h            # Manage Users submenu
│   │   ├── clsUsersListScreen.h
│   │   ├── clsAddNewUserScreen.h
│   │   ├── clsDeleteUserScreen.h
│   │   ├── clsUpdateUserScreen.h
│   │   └── clsFindUserScreen.h
│   │
│   ├── 💱 Currency Exchange Screens
│   │   ├── clsCurrencyExchangeMainScreen.h  # Currency submenu
│   │   ├── clsCurrenciesListScreen.h
│   │   ├── clsFindCurrencyScreen.h
│   │   ├── clsUpdateCurrencyRateScreen.h
│   │   └── clsCurrencyCalculatorScreen.h
│   │
│   └── clsLoginRegisterScreen.h    # Login history viewer
│
├── 🔧 Helper / Utility Classes
│   ├── clsInputValidate.h          # Input validation & safe reading
│   ├── clsString.h                 # String manipulation utilities
│   ├── clsDate.h                   # Date/time utilities
│   └── clsUtil.h                   # Encryption, random, number-to-text
│
├── 🌐 Global
│   └── Global.h                    # Global CurrentUser variable
│
└── 💾 Data Files
    ├── Clients.txt
    ├── Users.txt
    ├── Currencies.txt
    ├── LoginRegister.txt
    └── TransferLog.txt
```

---

## 💾 Data Storage

All data is persisted in plain text files using `#//#` as a field separator. No external database is required.

### `Clients.txt`
```
FirstName#//#LastName#//#Email#//#Phone#//#AccountNumber#//#PinCode#//#Balance
```
```
Mohammed#//#Abu-Hadhoud#//#msaqer@gmail.com#//#199192#//#A101#//#1234#//#4000.000000
```

### `Users.txt`
```
FirstName#//#LastName#//#Email#//#Phone#//#UserName#//#EncryptedPassword#//#Permissions
```
```
Hilal#//#Ali#//#Hilal@Gmail.com#//#83983948#//#User1#//#3456#//#49
```

### `LoginRegister.txt`
```
DateTime#//#UserName#//#EncryptedPassword#//#Permissions
```
```
25/6/2026 - 09:01:48#//#User1#//#3456#//#49
```

### `TransferLog.txt`
```
DateTime#//#SourceAccount#//#DestAccount#//#Amount#//#SrcBalanceAfter#//#DestBalanceAfter#//#UserName
```
```
25/6/2026 - 09:10:14#//#A101#//#A106#//#800.000000#//#4700.000000#//#8802.000000#//#User1
```

### `Currencies.txt`
```
Country#//#CurrencyCode#//#CurrencyName#//#RatePerUSD
```
```
Algeria#//#DZD#//#Algerian Dinar#//#137.046005
```

> 💡 **Note:** Passwords are never stored in plain text. A Caesar-cipher shift is applied before writing to disk and reversed when reading.

---

## 🔑 Permission System

Access control is enforced using an **integer bitmask**. Every user has a `Permissions` field, and every screen checks the relevant bit before showing any content.

| Permission | Bit Value | Description |
|---|---|---|
| `eAll` | `-1` | Full access to everything (Admin) |
| `pListClients` | `1` | View the client list |
| `pAddNewClient` | `2` | Add new clients |
| `pDeleteClient` | `4` | Delete clients |
| `pUpdateClient` | `8` | Update client info |
| `pFindClient` | `16` | Search for clients |
| `pTransactions` | `32` | Access the transactions menu |
| `pManageUsers` | `64` | Access the user management menu |
| `pShowLoginRegister` | `128` | View the login history |

**Example role assignments:**

| Role | Permissions Value | Access |
|---|---|---|
| Admin | `-1` | Everything |
| Manager | `251` | All except Delete Client |
| Teller | `49` | List + Find + Transactions |
| Data Entry | `7` | List + Add + Delete |
| Viewer | `17` | List + Find only |

Permissions are combined with the bitwise OR operator and checked with bitwise AND:
```cpp
// Granting permissions
_Permissions |= clsUser::enPermissions::pListClients;   // adds List
_Permissions |= clsUser::enPermissions::pTransactions;  // adds Transactions

// Checking permissions
if ((Permission & this->Permissions) == Permission) { /* granted */ }
```

---

## ▶️ How to Run

### Prerequisites
- Windows OS
- Visual Studio 2019 or later (or any C++ compiler supporting C++11)

### Steps

1. **Clone the repository**
   ```bash
   git clone https://github.com/your-username/Bank-System-with-Currency-Exchange.git
   ```

2. **Open the solution**
   - Double-click `Bank_System.sln` to open in Visual Studio

3. **Build and Run**
   - Press `Ctrl + F5` to build and run without debugging
   - Or use the menu: `Debug → Start Without Debugging`

4. **Make sure the data files are in the same directory as the executable**
   - `Clients.txt`
   - `Users.txt`
   - `Currencies.txt`
   - `LoginRegister.txt`
   - `TransferLog.txt`

   > The program creates `LoginRegister.txt` and `TransferLog.txt` automatically if they don't exist. The other three files must be present for the system to work.

5. **Login with an existing user**, for example:
   ```
   Username: User1
   Password: 3456
   ```

---

## 📦 Modules Overview

### Bank System
```
clsLoginScreen
    └── clsMainScreen
            ├── clsClientListScreen
            ├── clsAddNewClientScreen
            ├── clsDeleteClientScreen
            ├── clsUpdateClientScreen
            ├── clsFindClientScreen
            ├── clsTransactionsScreen
            │       ├── clsDepositScreen
            │       ├── clsWithdrawScreen
            │       ├── clsTransferScreen
            │       ├── clsTransferLogScreen
            │       └── clsTotalBalancesScreen
            ├── clsManageUsersScreen
            │       ├── clsUsersListScreen
            │       ├── clsAddNewUserScreen
            │       ├── clsDeleteUserScreen
            │       ├── clsUpdateUserScreen
            │       └── clsFindUserScreen
            ├── clsLoginRegisterScreen
            └── clsCurrencyExchangeMainScreen
                    ├── clsCurrenciesListScreen
                    ├── clsFindCurrencyScreen
                    ├── clsUpdateCurrencyRateScreen
                    └── clsCurrencyCalculatorScreen
```

### Class Hierarchy
```
clsPerson
    ├── clsBankClient
    └── clsUser

clsScreen
    ├── clsLoginScreen
    ├── clsMainScreen
    ├── clsClientListScreen
    ├── clsAddNewClientScreen
    ├── ... (all screen classes)
    └── clsCurrencyCalculatorScreen
```
