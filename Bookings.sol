// SPDX-License-Identifier: MIT
pragma solidity >=0.4.22 <0.8.0;
pragma experimental ABIEncoderV2;

/*In this code, I wrote a smart contract (of course there are plenty of more functionalities that can be added given more time) that
utilizes the Ethereum blockchain. I have tested this smart contract using Ganache (a local blockchain for testing) and it works
completetly fine. I have used only two resources to write this smart contract because there is very minimal documentation about
smart contracts on the blockchain because it is a very new field. This is my first ever time writing a full smart contract (I
started learning Solidity programming language 2 days ago). I was initially planning on writing front end 
code too but realized mid-way that it was too much. Hope you have fun reading this code. :)*/

//Starting a smart contract called bookings that will be deployed by the owner
contract Bookings{
    //Defining a struct Room that contains data about each room
    struct Room{
        uint Room_Number;
        string location;
        uint isAvailable;
        uint price;
    }
    //Defining a struct User that contains data about each user
    struct User{
        uint userNo;
        string fullName;
        uint netId;
        uint NoOfBookings;
    }

    //Defining the variable values for each of vacant and occupied
    uint Vacant = 0;
    uint Occupied = 1;

    //Setting the owner address to be the one that deploys the smart contract
    address payable private owner;

    //Declaring an event that triggers when a user occupies a room
    event Occupy(address _occupant, uint _value);

    //Declaring two mappings: one for users and one for rooms
    mapping(uint=>User) private Users;
    mapping(uint=>Room) private Rooms;
    uint private RoomCtr = 1;
    uint private UserCtr = 1;

    //Default constructor that initializes two objects (one room and one user) for testing purposes.
    //These objects can be removed by the owner who deploys the smart contract and
    //then they can declare their own users and rooms as they wish, and it would work completely fine.
    //Also, the default constructor initializes the owner of the smart contracts as the one who deploys it using the function msg.sender
    constructor() public{
        owner = msg.sender;    
        addRoom("Ahmad's Room", Vacant,5);
        addUser("Ahmad", 2200);
    }

    //Modifiers for the rooms to have constraints on the booking of a room (price and availability)
    modifier OnlyWhileVacant(uint _RoomNumber){
        require(Rooms[_RoomNumber].isAvailable == Vacant,"Currently occupied.");
        _;
    }

    modifier OnlyWhileOccupied(uint _RoomNumber){
        require(Rooms[_RoomNumber].isAvailable == Occupied, "Already vacant.");
        _;
    }
    
    modifier RoomCost(uint _amount){
        require(msg.value >= _amount, "Not enough money.");
        _;
    }

    //Getter functions to get the values inside the struct objects that are inside the Rooms mapping
    function getAvail(uint _RoomNumber) private view returns(uint){
        return Rooms[_RoomNumber].isAvailable;
    }

    function getLoc(uint _RoomNumber) private view returns(string memory){
        return Rooms[_RoomNumber].location;
    }

    function getPrice(uint _RoomNumber) private view returns(uint){
        return Rooms[_RoomNumber].price;
    }

    //Function to add a new room to the list of available rooms for reservation
    function addRoom(string memory _location, uint _avail, uint _price) public
    {
        Rooms[RoomCtr] = Room(RoomCtr, _location, _avail, _price);
        RoomCtr++;
    }

    //Functions that change the availability of the rooms based on whether booked or left
    function occupyRoom(uint _RoomNumber) private{
        Rooms[_RoomNumber] = Room(_RoomNumber, getLoc(_RoomNumber),Occupied, getPrice(_RoomNumber)); 
    }

    function emptyRoom(uint _RoomNumber) private{
        Rooms[_RoomNumber] = Room(_RoomNumber, getLoc(_RoomNumber),Vacant, getPrice(_RoomNumber)); 
    }

    //Main function that books a room using the room number and the user id
    function BookRoom(uint _RoomNumber, uint _userID) public payable OnlyWhileVacant(_RoomNumber) RoomCost(5 ether){
        incrementNoOfBookings(_userID);
        occupyRoom(_RoomNumber);
        owner.transfer(msg.value);
        emit Occupy(msg.sender,msg.value);
    }

    //Function that leaves a room
    function LeaveRoom(uint _RoomNumber) public OnlyWhileOccupied(_RoomNumber){
        emptyRoom(_RoomNumber);
    }

    //Function that returns the details of a room (Room number, Room location, Occupied or vacant, price)
    function CheckDetails(uint _RoomNumber) public view returns(Room memory)
    {
        return Rooms[_RoomNumber];
    }

    //Functions for Users
    //Function to add a new user to the list of available users
    function addUser(string memory _fullname, uint _netid) public
    {
        Users[UserCtr] = User(UserCtr, _fullname, _netid, 0);
        UserCtr++;
    }

    //Getter functions to get the values of the user objects that are inside the Users mapping
    function getNoBookings(uint _userID) private view returns(uint)
    {
        return Users[_userID].NoOfBookings;
    }

    function getName(uint _userID) private view returns(string memory)
    {
        return Users[_userID].fullName;
    }

    function getNetId(uint _userID) private view returns(uint)
    {
        return Users[_userID].netId;
    }

    //Functions to edit the user data and increment the number of bookings made by one user when they make a booking so 
    //it can be helpful in tracking the number of bookings one user has made.
    function incrementNoOfBookings(uint _userID) private{
        Users[_userID] = User(_userID, getName(_userID),getNetId(_userID), getNoBookings(_userID)+ 1 ); 
    }

    //Function that returns the details of a user (User number, User's Full Name, User's netId, User's total number of bookings made)
    function CheckUserDetails(uint _userID) public view returns(User memory)
    {
        return Users[_userID];
    }

}