# UML Diagrams

1. Class UML for(diagram

![Untitled](UML%20Diagrams%20504e0cf95ba04707b893c27111c25314/Untitled.png)

1. Sequence UML Diagram

![Untitled](UML%20Diagrams%20504e0cf95ba04707b893c27111c25314/Untitled%201.png)

```c
@startuml  
actor User

User -> Main: start()
activate Main

Main -> DBManager: DBManager()
activate DBManager

DBManager -> Database: createFile(sizeof(ClientModel), "client.dat")
activate Database
Database --> DBManager: true
deactivate Database

DBManager -> Database: createFile(sizeof(OrderModel), "order.dat")
activate Database
Database --> DBManager: true
deactivate Database

DBManager -> DBManager: loadIndexies()
activate DBManager
DBManager --> DBManager: masterIndex, slaveIndex
deactivate DBManager

deactivate DBManager

loop Main Loop
    User -> Main: execute()
    activate Main

    Main -> Main: printMenu()
    Main -> User: inputChoice()
    User -> Main: choice

    alt choice == 1
        Main -> Main: addClient()
        Main -> User: get client data
        User -> Main: client data
        Main -> DBManager: insertM(client)
        activate DBManager

        DBManager -> Database: writeRecord(address, byteArray, sizeof(ClientModel), "client.dat")
        activate Database
        Database --> DBManager: true
        deactivate Database

        DBManager -> DBManager: addIndex(masterIndex, index)
        DBManager -> DBManager: saveIndex(TableType::master)
        deactivate DBManager

    else choice == 2
        Main -> Main: removeClient()
        Main -> User: get phone number
        User -> Main: phone number
        Main -> DBManager: delM(phone number)
        activate DBManager

        DBManager -> DBManager: getM(phone number)
        DBManager -> DBManager: updateM(client)
        deactivate DBManager

    else choice == 3
        Main -> Main: addOrder()
        Main -> User: get order data
        User -> Main: order data
        Main -> DBManager: insertS(order)
        activate DBManager

        DBManager -> Database: writeRecord(address, byteArray, sizeof(OrderModel), "order.dat")
        activate Database
        Database --> DBManager: true
        deactivate Database

        DBManager -> DBManager: addIndex(slaveIndex, index)
        DBManager -> DBManager: saveIndex(TableType::slave)
        deactivate DBManager

    else choice == 4
        Main -> Main: removeOrder()
        Main -> User: get order id
        User -> Main: order id
        Main -> DBManager: delS(order id)
        activate DBManager

        DBManager -> DBManager: getS(order id)
        DBManager -> DBManager: updateS(order)
        deactivate DBManager

    else choice == 5
        Main -> Main: printClient()
        Main -> User: get phone number
        User -> Main: phone number
        Main -> DBManager: getM(phone number)
        activate DBManager
        DBManager --> Main: client
        deactivate DBManager

    else choice == 6
        Main -> Main: printOrder()
        Main -> User: get order id
        User -> Main: order id
        Main -> DBManager: getS(order id)
        activate DBManager
        DBManager --> Main: order
        deactivate DBManager

    else choice == 7
        Main -> Main: printClientCount()
        Main -> DBManager: calcM()
        activate DBManager
        DBManager --> Main: CalcMResult
        deactivate DBManager

    else choice == 8
        Main -> Main: printOrderCount()
        Main -> DBManager: calcS()
        activate DBManager
        DBManager --> Main: order count
        deactivate DBManager

    else choice == 9
        Main -> Main: clientInfo()
        Main -> DBManager: utM()
        activate DBManager
        DBManager --> Main: clients
        deactivate DBManager

    else choice == 10
        Main -> Main: orderInfo()
        Main -> DBManager: utS()
        activate DBManager
        DBManager --> Main: orders
        deactivate DBManager

    else choice == 11
        Main -> Main: updateClient()
        Main -> User: get client data
        User -> Main: client data
        Main -> DBManager: updateM(client)
        activate DBManager
        DBManager --> Main: true/false
        deactivate DBManager

    else choice == 12
        Main -> Main: updateOrder()
        Main -> User: get order data
        User -> Main: order data
        Main -> DBManager: updateS(order)
        activate DBManager
        DBManager --> Main: true/false
        deactivate DBManager

    else choice == 13
        Main -> Main: exit program
        return

    end
    deactivate Main
end
@enduml
```

Код на Plant UML

1. Activity diagram

![Untitled](UML%20Diagrams%20504e0cf95ba04707b893c27111c25314/Untitled%202.png)

```c
@startuml
|User|
start
:Enter Tracking Number;

|UI Framework|
:displayTrackingInfo;

|Order Tracking|
:getTrackingNumberFromUser;
:trackOrder(trackingNumber);

if (Order Found?) then (yes)
    :OrderDetails.getOrderDetails;
    :Delivery.getDeliveryDetails;
    :updateStatus(trackingNumber, status);
    :OrderStatus;
    |UI Framework|
    :displayTrackingInfo(orderStatus);
else (no)
    :displayError("Order not found");
endif

stop
@enduml

```

4.Component diagram

![Untitled](UML%20Diagrams%20504e0cf95ba04707b893c27111c25314/Untitled%203.png)

1. Package UML diagram

![Untitled](UML%20Diagrams%20504e0cf95ba04707b893c27111c25314/Untitled%204.png)

> Для створювання діаграм використовував Visual Paradigm, Plant uml
>
