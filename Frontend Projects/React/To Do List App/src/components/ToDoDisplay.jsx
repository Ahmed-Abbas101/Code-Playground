import React, { useState, useContext } from 'react'
import { TodoContext } from './TodoContext.jsx'
import '../App.css'

const TodoItem = ({ task, onToggle, onDelete }) => {
  return (
    <div className="tasks">
      <span
        className={`taskText ${task.completed ? 'completed' : ''}`}
        onClick={() => onToggle(task.id)}
      >
        {task.text}
      </span>
      <button
        className="deleteBtn"
        onClick={() => onDelete(task.id)}>
        Delete
      </button>
    </div>
  )
}

const ToDoDisplay = () => {
  const { tasks, toggleTask, removeTask } = useContext(TodoContext);

  if (tasks.length === 0) return <p className='empty'>No tasks yet!</p>;

  return (
    <div className='results'>
        {tasks.map(task => (
          <TodoItem
            key={task.id}
            task={task}
            onToggle={toggleTask}
            onDelete={removeTask}
          />
        ))}
    </div>
  )
}

export default ToDoDisplay;