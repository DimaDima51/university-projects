import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Hr {
    public static void main(String[] args) {
        List <Employee> staff = new ArrayList<> ();
        Scanner scanner = new Scanner(System.in);
        boolean running = true;

        while (running) {
            System.out.println("\n--- Меню отдела кадров ---");
            for (MenuOption option: MenuOption.values()) {
                System.out.println(option.getCode() + ". " + option.getDescription());
            }
            System.out.print("Выберите пункт: ");
            String command = scanner.nextLine().trim().toLowerCase();
            MenuOption selectedOption = MenuOption.fromCode(command);

            if (selectedOption != null) {
                switch (selectedOption) {
                case ADD_WORKER:
                    System.out.println("Кого добавить?");
                    for (WorkerType type: WorkerType.values()) {
                        System.out.println(type.getCode() + ". " + type.getDescription());
                    }
                    System.out.print("Ваш выбор: ");
                    String type = scanner.nextLine().trim();
                    WorkerType selectedType = WorkerType.fromCode(type);
                    if (selectedType == null) {
                        System.out.println("Неверный тип сотрудника.");
                        break;
                    }

                    System.out.print("Хотите автоматически назначить табельный номер? (+/-): ");
                    String autoAssignChoice = scanner.nextLine().trim();
                    int newId = 0;

                    if (autoAssignChoice.equals("+")) {
                        int maxId = 0;
                        for (Employee emp: staff) {
                            if (emp.getStuffNumber() > maxId) {
                                maxId = emp.getStuffNumber();
                            }
                        }

                        if (maxId == 99999) {
                            System.out.println("Ошибка: Табельные номера переполнены.");
                            continue;
                        }

                        if (staff.isEmpty()) {
                            newId = 1;
                        } else {
                            newId = maxId + 1;
                        }
                        System.out.printf("Назначен табельный номер: %s\n", newId);
                    } else {
                        System.out.print("Введите табельный номер вручную: ");
                        newId = Integer.parseInt(scanner.nextLine());
                        boolean idExists = false;
                        for (Employee emp: staff) {
                            if (emp.getStuffNumber() == newId) {
                                idExists = true;
                                break;
                            }
                        }

                        if (idExists) {
                            System.out.println("Табельный номер уже существует. Сотрудник не добавлен.");
                            continue;
                        } else {
                            System.out.printf("Табельный номер успешно назначен: %s\n", newId);
                        }
                    }

                    System.out.print("Фамилия: ");
                    String lastName = scanner.nextLine();

                    System.out.print("Имя: ");
                    String firstName = scanner.nextLine();

                    int priorExp = 0;
                    boolean correctPrior = false;
                    while (!correctPrior) {
                        System.out.print("Предыдущий стаж (лет): ");
                        priorExp = Integer.parseInt(scanner.nextLine());
                        if (priorExp >= 0) {
                            correctPrior = true;
                        } else {
                            System.out.println("Некорректный ввод стажа!");
                        }
                    }

                    System.out.print("Учёная степень (null если нет): ");
                    String degreeInput = scanner.nextLine().trim();
                    String degree = degreeInput.equals("null") ? null : degreeInput;

                    System.out.print("Учёное звание (null если нет): ");
                    String titleInput = scanner.nextLine().trim();
                    String title = titleInput.equals("null") ? null : titleInput;

                    if (selectedType == WorkerType.TEACHER) {
                        int methWorks = 0;
                        boolean correctMethWorks = false;
                        while (!correctMethWorks) {
                            System.out.print("Число методических работ: ");
                            methWorks = Integer.parseInt(scanner.nextLine());
                            if (methWorks >= 0) {
                                correctMethWorks = true;
                            } else {
                                System.out.println("Некорректный ввод числа методических работ!");
                            }
                        }

                        staff.add(new Teacher(newId, lastName, firstName, priorExp, degree, title, methWorks));
                        
                    } else if (selectedType == WorkerType.RESEARCHER) {
                        System.out.print("Научное звание (null если нет): ");
                        String rankInput = scanner.nextLine().trim();
                        String rank = rankInput.equals("null") ? null : rankInput;

                        System.out.print("Индекс Хирша (null если нет): ");
                        String hIndexInput = scanner.nextLine().trim();
                        Integer hIndex = hIndexInput.equals("null") ? null : Integer.parseInt(hIndexInput);

                        staff.add(new Researcher(newId, lastName, firstName, priorExp, degree, title, rank, hIndex));
                    }
                    break;

                case SHOW_WORKERS:
                    System.out.println("\n--- Список сотрудников ---");
                    if (staff.isEmpty()) {
                        System.out.println("Список пуст.");
                    } else {
                        for (Employee emp: staff) {
                            System.out.println(emp);
                        }
                    }
                    break;

                case FIND_WORKER:
                    System.out.print("Введите табельный номер: ");
                    int searchId = Integer.parseInt(scanner.nextLine());
                    boolean found = false;
                    for (Employee emp: staff) {
                        if (emp.getStuffNumber() == searchId) {
                            System.out.println(emp);
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        System.out.println("Сотрудник не найден.");
                    }
                    break;

                case EXIT:
                    running = false;
                    break;

                default:
                    System.out.println("Неверная команда. Попробуйте снова.");
                    break;
                }
            } else {
                System.out.println("Неверный пункт меню. Попробуйте снова.");
            }
        }

        scanner.close();
        System.out.println("Работа завершена.");
    }
}