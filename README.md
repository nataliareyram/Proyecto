# Bank Account simulator
#Idea: The goal of this project is to create a bank account simulator that includes essential banking features, such as deposit, withdrawal, and balance inquiry. This simulator serves as a practical and interactive tool that allows users to engage with core financial operations in a safe, simulated environment. Moreover, it will help the users develop important skills, such as financial literacy, logical thinking, and problem-solving, thus enhancing their technical knowledge while making the learning process enjoyable and accessible. Thanks to the class diagram drawn beforehand, this simulator will have a blueprint amd rubric to be followed in order to ensure the integration of all the elements intended, and to have a seamless relation between all the classes involved.




#Context and justification: The choice of this project stems from its relevance to a wide array of programming concepts that will be discussed in class, such as OOP and C++ knowledge. Designing a bank account system requires an understanding of data handling, user interface design, and other essential skills in computer science and software development.


![Diagrama de clases](Diagrama.drawio.png)


CLASS LIST:
- BANK:
-   -bankName: string
-   -location: string
-   -customers: List<Customer>
-   +Bank(bankName: string, location: string)
-   +getBankName(): string
-   +setBankName(bankName: string): void
-   +getLocation(): string
-   +setLocation(location: string): void
-   +getCustomer(customerID: string): Customer
-   +addCustomer(customer: Customer): void
-   +removeCustomer(customerID: string): void


- CUSTOMER:
-    -customerID: string
-    -name: string
-    -phoneNumber: int
-    -bankAcc: BankAccount
-    -investAcc: InvestmentAccount
-    -cardType: Card
-    +Customer(customerID: string, name: string, phoneNumber: int, bankAcc: BankAccount, investAcc: InvestmentAccount, cardType: Card)
-    +getCustomerID(): string
-    +setCustomerID(customerID: string): void
-    +getName(): string
-    +setName(name: string): void
-    +getPhoneNumber(): int
-    +setPhoneNumber(phoneNumber: int): void
-    +getBankAccount(): BankAccount
-    +setBankAccount(bankAcc: BankAccount): void
-    +getInvestmentAccount(): InvestmentAccount
-    +setInvestmentAccount(investAcc: InvestmentAccount): void
-    +getCard(): Card
-    +setCard(cardType: Card): void


- BANK ACCOUNT
-   #accountNumber: string
-   #balance: double
-   #ownerName: string
-   #accountType: string
-   +BankAccount(accountNumber: string, balance: double, ownerName: string, accountType: string, )
-   +setAccountNumber(accountNumber: string): void
-   +getAccountNumber(): string
-   +setBalance(balance: double): void
-   +getBalance(): double
-   +setOwnerName(ownerName: string): void
-   +getOwnerName(): string
-   +setAccountType(accountType: string): void
-   +getAccountType(): string
-   +deposit(amount: double): void
-   +withdraw(amount: double): void 


- INVESTMENT ACCOUNT
-   -investmentBalance: double
-   -growthRate: double
-   +InvestmentAccount(accountNumber: string, balance: double, ownerName: string, accountType: string, investmentBalance: double, growthRate: double)
-   +getInvestmentBalance(): double
-   +setInvestmentBalance(investmentBalance: double): void
-   +getGrowthRate(): double
-   +setGrowthRate(growthRate: double): void
-   +applyGrowth(): void
-   +transferToInvestment(amount: double): void
-   +withdrawFromInvestment(amount: double): void


- CARD
-   -credit: string
-   -debit: string
-   +Card(credit: string, debit: string)
-   +getCredit(): string
-   +setCredit(credit: string): void
-   +getDebit(): string
-   +setDebit(debit: string): void
