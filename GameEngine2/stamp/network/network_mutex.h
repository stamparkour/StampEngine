

//this will be a mutex where locking will affect all connected systems
//there will be shared and unique varients
//this will be used with socket streams to ensure data integrity
//there will also be a interface for converting classes to packets and back
//there will be a templated function that will detect if the object is serializable or not
// if not, then it will just copy the memory directly
// if it is serializable, then it will call the serialize function