<?php

namespace App\Controller;

use App\Entity\Classroom;
use App\Form\ClassroomType;
use App\Repository\ClassroomRepository;
use  Doctrine\Persistence\ManagerRegistry;
use Symfony\Bundle\FrameworkBundle\Controller\AbstractController;
use Symfony\Component\Form\Extension\Core\Type\SubmitType;
use Symfony\Component\HttpFoundation\Request;
use Symfony\Component\HttpFoundation\Response;
use Symfony\Component\Routing\Annotation\Route;

class ClassroomController extends AbstractController
{
    


    #[Route('/fetchClassroom', name: 'fetchClassroom')]
    public function fetchClassroom(ManagerRegistry $doctrine): Response
    {
        $classrooms = $doctrine->getRepository(Classroom::class)->findAll();
        return $this->render('classroom/show.html.twig',
            ["classrooms" => $classrooms]);
    }

    

    #[Route('/addClassroom', name: 'addClassroom')]
    public function  addClassroom(ManagerRegistry $doctrine, Request  $request) : Response
    { $classroom = new Classroom() ;
        $form = $this->createForm(ClassroomType::class, $classroom);
        $form->add('ajouter', SubmitType::class) ;
        $form->handleRequest($request);
        if ($form->isSubmitted())
        { $em = $doctrine->getManager();
            $em->persist($classroom);
            $em->flush();
            return $this->redirectToRoute('fetchClassroom');
        }
        return $this->renderForm("classroom/add.html.twig",
            ["f"=>$form]) ;


    }

    #[Route('/update/{id}', name: 'updateClassroom')]
    public function  updateClassroom(ManagerRegistry $doctrine,$id,  Request  $request) : Response
    { $classroom = $doctrine
        ->getRepository(Classroom::class)
        ->find($id);
        $form = $this->createForm(ClassroomType::class, $classroom);
        $form->add('update', SubmitType::class) ;
        $form->handleRequest($request);
        if ($form->isSubmitted())
        { $em = $doctrine->getManager();
            $em->flush();
            return $this->redirectToRoute('fetchClassroom');
        }
        return $this->renderForm("classroom/update.html.twig",
            ["f"=>$form]) ;


    }
   #[Route("/delete/{id}", name:'deleteClassroom')]
    public function delete($id, ManagerRegistry $doctrine)
    {$c = $doctrine
        ->getRepository(Classroom::class)
        ->find($id);
        $em = $doctrine->getManager();
        $em->remove($c);
        $em->flush() ;
        return $this->redirectToRoute('fetchClassroom');
    }


    #[Route('/add2', name: 'addc2')]
    public function  add2(ManagerRegistry $doctrine , Request $request) : Response
    { $c = new Classroom() ;
        if($request->isMethod('POST'))
        { $c->setName($request->get('name'));
            $em = $doctrine->getManager();
            $em->persist($c);
            $em->flush();
            return $this->redirectToRoute('fetchClassrooms');
        }
        return $this->render('classroom/add2.html.twig');

    }
    //Question 2 DQL
    #[Route('/findmoyenne/{id}', name: 'find_moyenne')]
    public function  findMoyenne( ClassroomRepository $repo ,$id   ) : Response
    {
        $classroom =$repo->find($id);
        $moyenne= $repo->findStudentByClassAVG($classroom->getName());
        return $this->render('classroom/find.html.twig', [
            "classroom" => $classroom,
            "moyenne"=>$moyenne]);
    }

}