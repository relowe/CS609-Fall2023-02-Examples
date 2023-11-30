package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func LoadData(companyName string) *Company {
	filename := companyName + ".dat"
	if _, err := os.Stat(filename); os.IsNotExist(err) {
		return NewCompany(companyName)
	}

	company := NewCompany(companyName)

	file, err := os.Open(filename)
	if err != nil {
		fmt.Println("Error opening file:", err)
		return nil
	}
	defer file.Close()

	scanner := bufio.NewScanner(file)

	numEmployees := readInt(scanner)
	for i := 0; i < numEmployees; i++ {
		name := readString(scanner)
		email := readString(scanner)
		phone := readString(scanner)
		salary := readFloat(scanner)

		employee := NewEmployee(name, email, phone, salary)
		company.AddEmployee(employee)
	}

	numCustomers := readInt(scanner)
	for i := 0; i < numCustomers; i++ {
		customerName := readString(scanner)
		customerEmail := readString(scanner)
		customerPhone := readString(scanner)

		customer := NewCustomer(customerName, customerEmail, customerPhone)

		numPurchases := readInt(scanner)
		for j := 0; j < numPurchases; j++ {
			item := readString(scanner)
			qty := readInt(scanner)
			cost := readFloat(scanner)

			purchase := NewPurchase(item, qty, cost)
			customer.AddPurchase(purchase)
		}

		company.AddCustomer(customer)
	}

	return company
}

// Helper functions to read different types of data from scanner
func readString(scanner *bufio.Scanner) string {
	scanner.Scan()
	return scanner.Text()
}

func readInt(scanner *bufio.Scanner) int {
	str := readString(scanner)
	num, _ := strconv.Atoi(str)
	return num
}

func readFloat(scanner *bufio.Scanner) float64 {
	str := readString(scanner)
	num, _ := strconv.ParseFloat(str, 64)
	return num
}

func SaveData(companyName string, company *Company) {
	filename := companyName + ".dat"
	file, err := os.Create(filename)
	if err != nil {
		fmt.Println("Error creating file:", err)
		return
	}
	defer file.Close()

	writer := bufio.NewWriter(file)

	// Writing employees data
	fmt.Fprintln(writer, len(company.Employees))
	for _, employee := range company.Employees {
		fmt.Fprintln(writer, employee.Name)
		fmt.Fprintln(writer, employee.Email)
		fmt.Fprintln(writer, employee.Phone)
		fmt.Fprintln(writer, employee.Salary)
	}

	// Writing customers data
	fmt.Fprintln(writer, len(company.Customers))
	for _, customer := range company.Customers {
		fmt.Fprintln(writer, customer.Name)
		fmt.Fprintln(writer, customer.Email)
		fmt.Fprintln(writer, customer.Phone)
		fmt.Fprintln(writer, len(customer.History))

		for _, purchase := range customer.History {
			fmt.Fprintln(writer, purchase.Item)
			fmt.Fprintln(writer, purchase.Qty)
			fmt.Fprintln(writer, purchase.Cost)
		}
	}

	writer.Flush()
}

func DisplayEmployees(company *Company) {
	fmt.Println("Employees:")
	for _, employee := range company.Employees {
		fmt.Printf("%s <%s> Phone: %s Salary: $%.2f\n", employee.Name, employee.Email, employee.Phone, employee.Salary)
	}
}

func AddEmployee(company *Company) {
	fmt.Println("Add Employee:")
	var name, email, phone string
	var salary float64

	fmt.Print("Name: ")
	fmt.Scanln(&name)
	fmt.Print("Email: ")
	fmt.Scanln(&email)
	fmt.Print("Phone: ")
	fmt.Scanln(&phone)
	fmt.Print("Salary: ")
	fmt.Scanln(&salary)

	employee := NewEmployee(name, email, phone, salary)
	company.AddEmployee(employee)
	fmt.Println("Employee added successfully.")
}

func DisplaySales(company *Company) {
	fmt.Println("Sales:")

	if len(company.Customers) == 0 {
		fmt.Println("Error: No Customers.")
		return
	}

	for index, customer := range company.Customers {
		fmt.Printf("%d.) %s\n", index+1, customer.Name)

		if len(customer.History) == 0 {
			fmt.Println("No purchases.")
		} else {
			fmt.Println("Order History")
			fmt.Println("Item Price Quantity Total")

			for _, purchase := range customer.History {
				total := purchase.Total()
				fmt.Printf("%s %.2f %d %.2f\n", purchase.Item, purchase.Cost, purchase.Qty, total)
			}
		}
	}
}

func ViewCustomerList(company *Company) {
	fmt.Println("Customer List:")
	for index, customer := range company.Customers {
		fmt.Printf("%d.) %s\n", index+1, customer.Name)
	}
}

func ViewCustomerInfo(company *Company) {
	ViewCustomerList(company)

	fmt.Print("Choice? ")
	var customerChoice int
	fmt.Scanln(&customerChoice)

	if customerChoice >= 1 && customerChoice <= len(company.Customers) {
		customer := company.Customers[customerChoice-1]
		fmt.Printf("%s <%s> Phone: %s\n", customer.Name, customer.Email, customer.Phone)

		if len(customer.History) == 0 {
			fmt.Println("No purchases.")
		} else {
			fmt.Println("Order History")
			fmt.Println("Item Price Quantity Total")

			for _, purchase := range customer.History {
				total := purchase.Total()
				fmt.Printf("%s %.2f %d %.2f\n", purchase.Item, purchase.Cost, purchase.Qty, total)
			}
		}
	} else {
		fmt.Println("Invalid choice.")
	}
}

func AddCustomerMenu(company *Company) {
	fmt.Println("Add Customer:")
	var name, email, phone string

	fmt.Print("Name: ")
	fmt.Scanln(&name)
	fmt.Print("Email: ")
	fmt.Scanln(&email)
	fmt.Print("Phone: ")
	fmt.Scanln(&phone)

	customer := NewCustomer(name, email, phone)
	company.AddCustomer(customer)

	fmt.Println("Customer added successfully.")
}

func AddSaleMenu(company *Company) {
	fmt.Println("Choose a customer to add a sale:")
	DisplayCustomersWithIDs(company)

	var customerID int
	fmt.Print("Enter the customer ID: ")
	fmt.Scanln(&customerID)

	if customerID < 1 || customerID > len(company.Customers) {
		fmt.Println("Invalid customer ID.")
		return
	}

	customer := company.Customers[customerID-1]

	var item string
	var qty int
	var cost float64

	fmt.Print("Item: ")
	fmt.Scanln(&item)
	fmt.Print("Quantity: ")
	fmt.Scanln(&qty)
	fmt.Print("Cost: ")
	fmt.Scanln(&cost)

	purchase := NewPurchase(item, qty, cost)
	customer.AddPurchase(purchase)

	fmt.Println("Sale added successfully.")
}

func DisplayCustomersWithIDs(company *Company) {
	fmt.Println("Customers:")

	for index, customer := range company.Customers {
		fmt.Printf("%d. %s <%s> Phone: %s\n", index+1, customer.Name, customer.Email, customer.Phone)
	}
}

func MainMenu(company *Company) {
	for {
		fmt.Println(" MAIN MENU")
		fmt.Println("1.) Employees")
		fmt.Println("2.) Sales")
		fmt.Println("3.) Quit")
		fmt.Print("Choice? ")

		var choice int
		fmt.Scanln(&choice)

		switch choice {
		case 1:
			for {
				fmt.Println(" EMPLOYEES MENU")
				fmt.Println("1.) View/Add Employees")
				fmt.Println("2.) Back to Main Menu")
				fmt.Print("Choice? ")

				var empChoice int
				fmt.Scanln(&empChoice)

				switch empChoice {
				case 1:
					DisplayEmployees(company)
					fmt.Print("(A)dd Employee or (M)ain Menu? ")
					var addEmpChoice string
					fmt.Scanln(&addEmpChoice)
					if strings.ToLower(addEmpChoice) == "a" {
						AddEmployee(company)
					}
				case 2:
					break
				default:
					fmt.Println("Invalid choice. Please try again.")
				}

				if empChoice == 2 {
					break
				}
			}
		case 2:
			for {
				fmt.Println(" SALES MENU")
				fmt.Println("1.) View/Add Sales and Customers")
				fmt.Println("2.) Back to Main Menu")
				fmt.Print("Choice? ")

				var salesChoice int
				fmt.Scanln(&salesChoice)

				switch salesChoice {
				case 1:
					for {
						fmt.Println("(A)dd Customer, Enter a (S)ale, (V)iew Customer, or (M)ain Menu?")
						fmt.Print("Choice? ")
						var saleChoice string
						fmt.Scanln(&saleChoice)

						switch saleChoice {
						case "a":
							AddCustomerMenu(company)
						case "s":
							AddSaleMenu(company)
						case "v":
							ViewCustomerInfo(company)

							fmt.Println("Press enter to continue...")
							var pause string
							fmt.Scanln(&pause)

						case "m":
							break
						default:
							fmt.Println("Invalid choice. Please try again.")
						}

						if saleChoice == "m" {
							break
						}
					}
				case 2:
					break
				default:
					fmt.Println("Invalid choice. Please try again.")
				}

				if salesChoice == 2 {
					break
				}
			}
		case 3:
			SaveData(company.Name, company)
			return
		default:
			fmt.Println("Invalid choice. Please try again.")
		}
	}
}

func main() {
	fmt.Print("Company Name: ")
	var companyName string
	fmt.Scanln(&companyName)

	company := LoadData(companyName)
	if company == nil {
		company = NewCompany(companyName)
	}

	MainMenu(company)
}
