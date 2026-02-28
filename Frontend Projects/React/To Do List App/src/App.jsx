import React from 'react'
import {TodoProvider} from './components/TodoContext'
import TodoList from './components/TodoList'
import ToDoDisplay from './components/ToDoDisplay'

const App =()=>{
  return(
      <TodoProvider>
        <div className='container'>
          <h1 style={{textAlign:'center'}}>To Do App</h1>
          <TodoList />

          <hr />

          <ToDoDisplay />
        </div>
      </TodoProvider>

  )
}

export default App;